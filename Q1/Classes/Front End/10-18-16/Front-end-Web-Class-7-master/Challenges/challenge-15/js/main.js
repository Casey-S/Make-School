// Compile Template
var projectTemplate = Handlebars.compile($("#project-template").html());
var navTemplate = Handlebars.compile($("#nav-template").html());

// Loop through data and display content 
var content = "";
var navContent = "";
for (var i in data) {
    content += projectTemplate(data[i]);
    navContent += navTemplate(data[i]);
}

// Add the content to the page
$("#content").html(content);
$("#nav").html(navContent);

// handle the links 
$("#nav a").click(function(event){
    $(".box").removeClass("show");
    $($(this).attr("href")).addClass("show");
});