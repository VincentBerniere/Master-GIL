function printBart() {
	var btn = document.getElementById('punir');
	var texte = document.getElementById('puni_text');
	var tableau = document.getElementById('writing_area');

	btn.onclick = function() {
		for (var i=0; i<=10;i++) {
			tableau.innerHTML = texte.value;
		}
	}
}

printBart();