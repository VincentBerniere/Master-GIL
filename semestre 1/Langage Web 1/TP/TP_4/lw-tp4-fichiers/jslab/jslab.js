/*var newObject = {
	nom : "BERNIERE",
	age : 21,
	majeur : true,
	adresse : {num : 1,  rue : 'rue Mac Orlan'},
	travail : function(){ return  false; },
};

function printObject(object) {
  var s = "Object ";
  s += object;
  s += " : [";
  s += typeof(object) 
  s += "] = <br>";
  
  var element = document.querySelector('#sortie');
  
  for(var prop in object) {
    s += prop + ' : ' + typeof(object[prop]) + ' = ' + object[prop] + '<br>'
  }
  element.innerHTML = s;
}

function rect(lon, lar) {
	this.longueur = lon;
	this.largeur = lar;
}

var r = new rect(10,20);

printObject(rect); // 
printObject(rect.prototype); // Object [object Object] : [object] = 
printObject(r); // longueur : number = 10; largeur : number = 20

var proto = rect.prototype;
proto.color = 'blue';

printObject(r); // longueur : number = 10; largeur : number = 20; color : string = blue
*/
function printArbre(node, indent) {
	var sortie = indent+node.nodeName+"<br/>";
	var child = node.firstChild;
	while(child) {
		sortie += printArbre(child, indent+" ");
		child = child.nextSibling;
	} 
	return sortie;
}

var s = printArbre(document.body," ");
document.getElementById('sortie').innerHTML = "<pre>"+printArbre(document," ")+"</pre>";

// Changer nom du button
var bt = document.getElementById('button1');
bt.value = "Clear !";
bt.onclick = function() {
	document.getElementById("sortie").innerHTML = bt;
}

// changer style des éléments
var l = document.getElementsByTagName('div');
for(var i=0; i<l.length; i++) {
	if(l[i].className = "module") l[i].className = "module_bis";
}
