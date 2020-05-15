var data = []

$(".challenge-list-item").each(function(){
    $file_name = $(this).attr("href");
    $file_name = $file_name.split("/",3)[2];
    $title = $(this).find(".challengecard-title").clone().children().remove().end().text();
    data.push([$file_name, $title]);
});

console.log(copy(data));
