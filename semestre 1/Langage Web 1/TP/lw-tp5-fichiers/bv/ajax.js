function createXhrObject() {
     if (window.XMLHttpRequest)
          return new XMLHttpRequest();
 
	if (window.ActiveXObject) {
        var names = [
            "Msxml2.XMLHTTP.6.0",
            "Msxml2.XMLHTTP.3.0",
            "Msxml2.XMLHTTP",
            "Microsoft.XMLHTTP"
        ];
        for(var i in names) {
            try {
                 return new ActiveXObject(names[i]); 
            } catch(e) {}
        }
    }
    return null; // not supported
}

/*function updateData() {
	if ( xhr.readyState == 4 ) // Telechargement fini.
 	if ( xhr.status == 200 ) { // Pas d’erreur.
	 	var dt=xhr.responseXML; // Un objet DOM element
	 	// Exploitation ave DOM :
	 	var cours=dt.getElementsByTagName("Cours") ;
	 	var msg="Liste des cours : ";
	 	for ( var i =0; i <cours.length; ++i ) {
	 		msg += cours[i].attributes[ "label" ].value;
		}
		alert(msg);
	}
 	else alert("Erreur : "+xhr.statusText);
}*/

function update() {
	// Instanciation :

	xhr = createXhrObject();
	//xhr.onreadystatechange = updateData;
	saisie = document.getElementById("puni_text").value;
	xhr.open("GET" , saisie, false);
	try{xhr.send(null); // Appel non bloquant
		var em = document.getElementById('writing_area');
		
	}
	if (!xhr) window.alert("Votre navigateur ne prend pas en charge l’objet XMLHTTPRequest.");
}
