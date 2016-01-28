
function sommaire(){
	var titles = document.querySelectorAll('h2, h3, h4, h5');
	for(var i = 0; i < titles.length; i++) {
	   	var title = titles[i];
		var lvl = parseInt(title.tagName.replace('H', ''))
		var div = document.createElement("DIV");
		div.setAttribute("class", "somH" + lvl);
		var a = document.createElement("A");
		var t = document.createTextNode(titles[i].textContent);
		a.appendChild(t);
		a.href= '#' + titles[i].id;
		div.appendChild(a);
		document.getElementById('sommaire').appendChild(div);
	}
}
