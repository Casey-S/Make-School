# Front-end-Web-Class-7

## Objectives

- Use jQuery
- Analyze jQuery's selector and pattern
- Build a site with jQuery
- Use Templates in a page

## Schedule

|   | Time |    | Activity    | Description                         |
|---|------|----|-------------|-------------------------------------|
| 1 | 5 min|  5 | TT          | jQuery Intro                        |
| 2 | 5 min| 10 | TT          | Handlebars JS                       |
| 3 | 5 min| 15 | TT          | Challenges Intro                    |
| 4 |30 min| 45 | Work        | Work on challenges                  |
| 5 |10 min| 55 | Break       |                                     |
| 6 |40 min| 95 | Work        | Work on challenges                  |
| 7 | 5 min| 15 | Discussion  | Posting your work                   |

### 1 - jQuery

jQuery is a library of helper functions written in JavaScript. 
jQuery provides an easier way of selecting elements and performing
common tasks with JavaScript. 

The jQuery function looks like this: 

`$()`

Pass in a CSS selector to create a collection of elements jQuery will 
act on. For example:

`$('div') // Creates a collection of div tags`

`$('.box') // Creates a collection of all elements with the class name box`

jQuery always returns a refernce to itself and keeps a collection of the last selection. 
This allows you to chain method calls like this: 

`$('.box').removeClass('hello').addClass('good-bye')`

Both removeClass() and addClass() are jQuery methods.
In this case removeClass('hello') is applied to all elements with the class name "box", 
then addClass('good-bye') is applied to all those elements. 

This is a very flexible system, it takes some practice to get understand all of the possibilities. 

### 2 - Handlebars JS

Handlebars is a JS templating engine. 
You create templates using standard HTML in script tags.
Then compile your templates into factory functions. 
These functions take an object as a prameter and return a populated template string. 

### 3 - Challenge Intro

Start the challenges from the: Start-Here project. 
You can download the [Start-Here.zip](Start-Here.zip) file. 

For the challenges I used the following jQuery methods: 

- .html('string') gets, sets the content of a tag. 
- .addClass('class-name') sets a class name
- .removeClass('class-name') removes a class name
- .click(function(){}) handles a click event on an element with the closure
- .attr(['name']) gets or sets the value of an attribute
- .animate({}, time) animates a property

For the examples I have set up handles and a single template in the starter project. 
The script tag containing the template is in index.html.
You will need to modify this template to complete some of the challenges. 

### 2 - In class challenges

- [Challenge 1](http://webdevils.com/make-school/front-end-web-class-7/challenges/challenge-1/)
- [Challenge 2](http://webdevils.com/make-school/front-end-web-class-7/challenges/challenge-2/)
- [Challenge 3](http://webdevils.com/make-school/front-end-web-class-7/challenges/challenge-3/)
- [Challenge 4](http://webdevils.com/make-school/front-end-web-class-7/challenges/challenge-4/)
- [Challenge 5](http://webdevils.com/make-school/front-end-web-class-7/challenges/challenge-5/)
- [Challenge 6](http://webdevils.com/make-school/front-end-web-class-7/challenges/challenge-6/)
- [Challenge 7](http://webdevils.com/make-school/front-end-web-class-7/challenges/challenge-7/)
- [Challenge 8](http://webdevils.com/make-school/front-end-web-class-7/challenges/challenge-8/)
- [Challenge 9](http://webdevils.com/make-school/front-end-web-class-7/challenges/challenge-9/)
- [Challenge 10](http://webdevils.com/make-school/front-end-web-class-7/challenges/challenge-10/)
- [Challenge 11](http://webdevils.com/make-school/front-end-web-class-7/challenges/challenge-11/)
- [Challenge 12](http://webdevils.com/make-school/front-end-web-class-7/challenges/challenge-12/)
- [Challenge 13](http://webdevils.com/make-school/front-end-web-class-7/challenges/challenge-13/)
- [Challenge 14](http://webdevils.com/make-school/front-end-web-class-7/challenges/challenge-14/)
- [Challenge 15](http://webdevils.com/make-school/front-end-web-class-7/challenges/challenge-15/)
- [Challenge 16](http://webdevils.com/make-school/front-end-web-class-7/challenges/challenge-16/)

## Challenges/Projects

Post your work and review the work of other students. 
You can post any/all of the web sites you have created. 
They can be in any state of completion. 
The goal is to get feedback which you can apply to your work. 

Do the following:

- Make your work available on the web for viewing an comments.
    - Post your work to the web.
        - If you don't have a web host you can: 
            - Talk to Tassos, he offered to provide hosting for studnets that may need it. 
            - Post your work via [Github Pages](https://pages.github.com)
                - NOTE! Github Pages allows only a single web site.
    - Create a Github project for your work.
        - Include a link to the website in the readme. 
        - Add a short description.
        - Include suggestions for what type of feedback would helpful.
    - Post a link to the Github project on Slack. 
    - Review and comment on everyone's work by posting issues to the Github project. 
        - It's important to review the work of others for their benefit and your benefit. 
        There is a lot to learn by analyzing the work of others. Ask yourself:
            - How did they do what they did here? 
            - Why did they do what they did in this situation? 
            - Where do you think it could be improved?
            - What is working best? 
            - You can divide comments into:
                - Content presented
                - Design
                - User Experience
            
    

