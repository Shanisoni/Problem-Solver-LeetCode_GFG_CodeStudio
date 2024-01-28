<input type="text" onchange="changeHandler(event)" />
<h1 id="hh"></h1>
<input type="button" onclick="shani(event)" />
<div id="c1" class="">
  
</div>


.mycircle{
    width:100px;
    border: 2px solid green;
    height:100px;
    border-radius:50%;
    
  }


  function changeHandler(event) {
    const shani = document.getElementById("hh");
    shani.innerHTML = event.target.value;
  }
  function shani(event){
   var g = document.getElementById("c1")
   g.classList.add("mycircle")
  }