var liste = document.querySelector('#select1');


liste.addEventListener('change', function(e) {
  e.preventDefault();
  var req = new XMLHttpRequest();
  req.open('GET', 'ajax_json.php?commune=' + this.value);
  req.setRequestHeader('Access-Control-Allow-Origin', '*');
  req.addEventListener('load', function() {
    var status = this.status;
    if (status == 200) {
      var obj = JSON.parse(this.responseText);
      obj.forEach(function(val) {
        var elt = document.createElement('option');
        elt.innerHTML = val.nom;
        elt.value = val.code;

        document.querySelector('#select2').innerHTML = '';
        document.querySelector('#select2').appendChild(elt);
      });
      // document.querySelector('#select2').innerHTML = this.responseText;
    } else {
      alert('Erreur lors du chargement\nActualisez la page.');
    }
  });

  req.send();
});