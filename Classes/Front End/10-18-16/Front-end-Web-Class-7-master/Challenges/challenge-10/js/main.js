// Compile Template
var projectTemplate = Handlebars.compile($("#project-template").html());

// Loop through data and display content 
var content = "";
for (var i in data) {
    content += projectTemplate(data[i]);
}

// Add the content to the page
$("#content").html(content);