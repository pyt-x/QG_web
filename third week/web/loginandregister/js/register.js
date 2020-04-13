let re_btn = document.getElementById('re')
let lg_btn = document.getElementById('lg')
let serverUrl = 'http://recruit.qgailab.com/'

var TurnToLogin = document.getElementById('jump_to_login');
var TurnToRegister = document.getElementById('jump_to_register');
var LoginContainer = document.getElementById("Login");
var RegisterContainer = document.getElementById("Register_container");
var JumpToRegister = TurnToRegister.onclick = () =>{
		
	LoginContainer.style.display = "none";
	RegisterContainer.style.display = "block";
		
}

var JumpTologin = TurnToLogin.onclick = () =>{
	
	LoginContainer.style.display = "block";
	RegisterContainer.style.display = "none";
		
}
/*原生ajax向浏览器发送数据*/

var xmlhttp;	//避免不兼容问题
if (window.XMLHttpRequest)
{
	xmlhttp=new XMLHttpRequest();
}
else
{
	xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
}

lg_btn.onclick = function(){
	let data = {
		username: document.getElementById('lg_username').value,
		password: document.getElementById('lg_password').value,
	}
	xmlhttp.open("POST",serverUrl+"ajax/register",true);
	xmlhttp.setRequestHeader("Content-type","application/json");
	xmlhttp.send(data);
	data: JSON.stringify(data);
	if (data.code === 1) {
	    alert(data.message)
	} else {
	    alert(data.message)
	}
}

re_btn.onclick = function(){
	let data = {
		username: document.getElementById('re_username').value,
		password: document.getElementById('re_password').value,
		email: document.getElementById('re_email').value,
	}
	xmlhttp.open("POST",serverUrl+"ajax/register",true);
	xmlhttp.setRequestHeader("Content-type","application/json");
	xmlhttp.send(data);
	data: JSON.stringify(data);
	if (data.code === 1) {
	    alert(data.message)
	} else {
	    alert(data.message)
	}
}


