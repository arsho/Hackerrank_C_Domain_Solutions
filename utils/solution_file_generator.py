import datetime
import os
import json


USERNAME = "arsho"
EXTENSION = ".c"


def get_valid_filename(title):
    title = title.lower()
    title = title.replace(" ", "_")
    title = "".join([c for c in title if (c>='a' and c<='z') or c=='_'])
    return title

def get_json_data(filename):
    with open(filename) as fp:
        data = json.load(fp)
        return data

def create_solution_files(data, username, extension):
    readme_data = {}
    for sub_domain in data:
        directory_name = get_valid_filename(sub_domain)
        directory_path = make_sub_domain_directory(directory_name)
        readme_data[(sub_domain, directory_name)] = []
        for challenge_data in data[sub_domain]:
            challenge = challenge_data[1]
            challenge_file_name = get_valid_filename(challenge) +"_"+ username + extension
            solution_file_path = make_solution_file(challenge, challenge_file_name, sub_domain, directory_path, username)
            readme_data[(sub_domain, directory_name)].append([challenge, solution_file_path])
    create_readme_file(readme_data, "README_generated.md")


def get_readme_content(data):
    lines = ""
    for sub_domain in data:
        lines += "- ["+sub_domain[0]+"]("+sub_domain[1]+")\n"
        for challenge in data[sub_domain]:
            lines += "   - ["+challenge[0]+"]("+challenge[1]+")\n"
    return lines

def create_readme_file(data, readme_filename):
    with open(readme_filename, "w") as fp:
        fp.writelines(get_readme_content(data))

def make_sub_domain_directory(directory_name):
    current_path = os.path.dirname(os.path.realpath(__file__))
    directory = os.path.join(current_path, directory_name)
    if not os.path.exists(directory):
        os.makedirs(directory)
    return str(directory)

def make_solution_file(challenge, challenge_file_name, sub_domain, directory_path, username):
    current_path = os.path.dirname(os.path.realpath(__file__))
    file_path = os.path.join(directory_path, challenge_file_name)
    if not os.path.exists(file_path):
        with open(file_path, "w") as f:
            f.writelines(write_file_header(challenge, sub_domain, username))
    return os.path.relpath(file_path, current_path)

def write_file_header(title, category, username):
    created_date = datetime.datetime.today().strftime("%d %B %Y")
    header_str = '/*\n'
    header_str += 'Title     : ' + title + '\n'
    header_str += 'Category  : ' + category + '\n'
    header_str += 'Author    : ' + username + '\n'
    header_str += 'Created   : ' + created_date + '\n'
    header_str += '*/\n\n\n'
    return header_str

def get_username():
    username = input("Username (keep blank for " + USERNAME + "): ").strip()
    if username == '':
        username = USERNAME
    return username

if __name__ == '__main__':
    username = get_username()
    challenge_data = get_json_data("challenges.json")
    create_solution_files(challenge_data, username, EXTENSION)
    print("Done. Check current folder.")
