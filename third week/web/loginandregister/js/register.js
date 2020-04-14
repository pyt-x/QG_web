var re_btn = document.getElementById('re')
var lg_btn = document.getElementById('lg')
var serverUrl = 'http://recruit.qgailab.com/'

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
	xmlhttp.open("POST",serverUrl+"ajax/login",true);
	xmlhttp.setRequestHeader("Content-type","application/json");
	xmlhttp.send(JSON.stringify(data));		//直接把data转化并提交给服务器;
	xmlhttp.onreadystatechange=function(){
	if (xmlhttp.readyState==4 && xmlhttp.status==200){
			let response = JSON.parse(xmlhttp.responseText);
			if (response.code === 1) {
				alert(response.message)
			} else {
				alert(response.message)
			}
		}
	}
}

re_btn.onclick = function(){
	let data = {
		username: document.getElementById('re_username').value,
		password: document.getElementById('re_password').value,
		email: document.getElementById('re_email').value,
		phone: document.getElementById('re_phone').value,
		name: document.getElementById('re_name').value,
	}
	xmlhttp.open("POST",serverUrl+"ajax/register",true);
	xmlhttp.setRequestHeader("Content-type","application/json");
	xmlhttp.send(JSON.stringify(data));
	xmlhttp.onreadystatechange=function(){
	  if (xmlhttp.readyState==4 && xmlhttp.status==200)
	    {
			let response = JSON.parse(xmlhttp.responseText);
			if (response.code === 1) {
				alert(response.message)
			} else {
				alert(response.message)
            }
	    }
	}
}


