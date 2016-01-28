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

function updateData() {
    if ( xhr.readyState == 4 ) { // terminé
        if ( xhr.status == 200 ) { // Pas d’erreur.
            var dt = xhr.responseText;
            document.getElementById('select2').innerHTML = dt;
        }
        else alert("Erreur : "+xhr.statusText);
    }
}

function update() {
    // Instanciation :

    xhr = createXhrObject();

    var select1 = document.getElementById("select1");

    xhr.onreadystatechange = updateData;

    xhr.open("GET" , "ajax.php?commune="+select1.value, true);

    xhr.send();
    

    if (!xhr) window.alert("Votre navigateur ne prend pas en charge l’objet XMLHTTPRequest.");
}