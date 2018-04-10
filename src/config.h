#include <Arduino.h>

// Hotspot specific settings
#define HOTSPOT_SSID "Waffle"
#define HOTSPOT_PASSWD "PrettyFlyForAWiFi"

#define HOTSPOT_IP 192,168,0,1
#define HOTSPOT_DOMAIN "waffle.net"
#define HOTSPOT_GATEWAY 192,168,0,1
#define HOTSPOT_SUBNET 255,255,255,0

// Hotspot idle timeout (900000 millis are 15 minutes)
#define EXIT_HOTSPOT_AFTER_MILLISECONDS_IDLE 900000

/* The following variables contain the html, css and js for the configuration pages.
You can edit them if you like. We will provide separate repository for the config pages
and the toolchain (minifying, uglyfying, escaping, etc) in the near future */
#ifndef __CONFIG_PAGE_H
#define __CONFIG_PAGE_H
const char CONFIG_CSS[] PROGMEM = "html,body{width:100%;margin:0;padding:0}body{background:#ff2961;background:linear-gradient(135deg, #ff2961 0%, #ff2961 20%, #9872ed 100%);margin:30px 0 20px;min-height:calc(100vh - 50px)}*{font-family:Tahoma, Geneva, sans-serif;color:#222}::selection,::-moz-selection{background:#ff2961;color:#fff}h1{font-size:1.5em;color:#ff2961;background:linear-gradient(135deg, #ff2961, #9872ed);-webkit-background-clip:text;-webkit-text-fill-color:transparent;margin:0;margin-bottom:10px}.toggleBtn{background:none;border:none;margin:0;padding:0;outline:none;cursor:pointer}.toggleBtn:before{content:'\\00BB';padding-right:5px}.toggleBtn:focus,.toggleBtn:hover{color:#ff2961}.toggleText{margin-top:10px}.toggleText.hidden{display:none}.logo-spacer{height:90px;width:100%;margin:0 0 30px}.logo-spacer .logo-container{position:absolute;width:90px;height:90px;margin:auto;top:75px;left:50%;transform:translate(-50%, -50%);text-align:center;z-index:10;transition:all 0.25s}.logo-spacer .logo-container.centered{position:fixed;top:50%}.logo-spacer .logo-container .logo{height:90px;width:auto}.logo-spacer .logo-container .circle-loader{position:absolute;left:-17px;top:-17px;border:2px solid rgba(0,0,0,0.2);border-left-color:#fff;display:inline-block;opacity:0;transition:border 0.25s}.logo-spacer .logo-container .circle-loader.active{opacity:1;animation-name:loader-spin;animation-duration:1s;animation-iteration-count:infinite;animation-timing-function:linear}.logo-spacer .logo-container .circle-loader.success,.logo-spacer .logo-container .circle-loader.error{-webkit-animation:none;animation:none;transition:border 500ms ease-out}.logo-spacer .logo-container .circle-loader.done{border-color:#fff}.logo-spacer .logo-container .circle-loader,.logo-spacer .logo-container .circle-loader:after{border-radius:50%;width:120px;height:120px}@keyframes loader-spin{0%{transform:rotate(0deg)}100%{transform:rotate(360deg)}}#Form{background:#fff;max-width:calc(85% - 40px);min-width:75%;min-height:calc(60% - 60px);padding:20px 20px;border-radius:5px;box-shadow:4px 4px 4px rgba(0,0,0,0.15);margin:auto}label,select,input{display:block;box-sizing:border-box;width:100%;font-family:sans-serif}label{font-size:.8em;margin-bottom:5px;color:#444}select,input{background:transparent;padding:6px 4px;border:none;border-bottom:1px solid #444;outline:none;border-radius:0;transition:all 0.2s}select:focus,input:focus{border-color:#ff2961}.form-group{margin-bottom:20px}.form-group+h1{margin-top:20px}.input-group{display:flex}.btn{display:block;margin:25px auto 0;border:none;background-color:transparent;color:#fff;padding:10px 20px;font-size:1.1em;border-radius:4px;outline:none;transition:all 0.25s}.btn.btn-refresh{margin:0;background-image:url(data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiA/PjwhRE9DVFlQRSBzdmcgIFBVQkxJQyAnLS8vVzNDLy9EVEQgU1ZHIDEuMS8vRU4nICAnaHR0cDovL3d3dy53My5vcmcvR3JhcGhpY3MvU1ZHLzEuMS9EVEQvc3ZnMTEuZHRkJz48c3ZnIGVuYWJsZS1iYWNrZ3JvdW5kPSJuZXcgMCAwIDMyIDMyIiBoZWlnaHQ9IjMycHgiIGlkPSJMYXllcl8xIiB2ZXJzaW9uPSIxLjEiIHZpZXdCb3g9IjAgMCAzMiAzMiIgd2lkdGg9IjMycHgiIHhtbDpzcGFjZT0icHJlc2VydmUiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgeG1sbnM6eGxpbms9Imh0dHA6Ly93d3cudzMub3JnLzE5OTkveGxpbmsiPjxnPjxwYXRoIGQ9Ik0yNS40NDQsNC4yOTFjMCwwLTEuMzI1LDEuMjkzLTIuMjQzLDIuMjAxQzE4LjUxNCwzLjA2OCwxMS45MDksMy40NTYsNy42NzYsNy42ODkgICBjLTIuNDcsMi40Ny0zLjYyMyw1Ljc0Ny0zLjQ4NCw4Ljk4M2g0QzguMDUxLDE0LjQ2LDguODEsMTIuMjA1LDEwLjUsMTAuNTE0YzIuNjYzLTIuNjYzLDYuNzM1LTMuMDQzLDkuODEyLTEuMTYyICAgYy0xLjA0MiwxLjAzMi0yLjI0NSwyLjIzOC0yLjI0NSwyLjIzOGMtMC44NDEsMS4wMDksMC4xMDQsMS41OTIsMC41ODQsMS41NzdsNS42MjQtMC4wMDFjMC4yOTcsMCwwLjUzOSwwLjAwMSwwLjUzOSwwLjAwMSAgIHMwLjI0NSwwLDAuNTQzLDBoMS4wOTJjMC4yOTgsMCwwLjU0LTAuMjQzLDAuNTQtMC41NDFWNC44OTVDMjcuMDIzLDQuMTg4LDI2LjI0NywzLjUwMiwyNS40NDQsNC4yOTF6IiBmaWxsPSIjZmYyOTYxIi8+PHBhdGggZD0iTTYuNTU1LDI3LjcwOWMwLDAsMS4zMjYtMS4yOTMsMi4yNDMtMi4yMDFjNC42ODgsMy40MjQsMTEuMjkyLDMuMDM2LDE1LjUyNi0xLjE5NyAgIGMyLjQ3LTIuNDcxLDMuNjIyLTUuNzQ3LDMuNDg0LTguOTgzaC00LjAwMWMwLjE0MiwyLjIxMS0wLjYxNyw0LjQ2Ny0yLjMwOCw2LjE1OWMtMi42NjMsMi42NjItNi43MzUsMy4wNDMtOS44MTIsMS4xNjEgICBjMS4wNDItMS4wMzIsMi4yNDUtMi4yMzgsMi4yNDUtMi4yMzhjMC44NDEtMS4wMS0wLjEwNC0xLjU5Mi0wLjU4NC0xLjU3N2wtNS42MjQsMC4wMDJjLTAuMjk3LDAtMC41NC0wLjAwMi0wLjU0LTAuMDAyICAgcy0wLjI0NSwwLTAuNTQzLDBINS41NTFjLTAuMjk4LDAtMC41NCwwLjI0Mi0wLjU0MSwwLjU0MXY3LjczMkM0Ljk3NywyNy44MTIsNS43NTMsMjguNDk4LDYuNTU1LDI3LjcwOXoiIGZpbGw9IiNmZjI5NjEiLz48L2c+PC9zdmc+);background-position:center;background-repeat:no-repeat;background-size:25px;width:21px;height:21px;padding:0;margin-left:10px}.btn.btn-submit{background-color:#ff2961;box-shadow:2px 2px 3px rgba(0,0,0,0.15);background:linear-gradient(135deg, #ff2961 0%, #9872ed 100%)}.btn.btn-submit:hover,.btn.btn-submit:focus{background:#ff7763;background:linear-gradient(135deg, #ff4374 0%, #a989f0 100%)}.spin{animation:spin 2s infinite linear;transform-origin:center}@keyframes spin{from{transform:rotate(0deg)}to{transform:rotate(360deg)}}.overlay{position:fixed;top:0;left:0;width:100%;height:100%;display:flex;flex-direction:column;align-items:center;justify-content:center;background:linear-gradient(135deg, #ff2961 0%, #ff2961 20%, #9872ed 100%);opacity:0;transition:all 0.25s;pointer-events:none;z-index:1}.overlay.open{opacity:1;pointer-events:auto}.overlay.success{background:linear-gradient(135deg, #c9ff5d 0%, #7b952e 100%)}.overlay.error{background:linear-gradient(135deg, #f50040 0%, #a9002c 100%)}.overlay .text{position:absolute;top:50%;margin-top:85px;left:20px;right:20px;text-align:center;font-weight:bold;color:#fff}.overlay .text small{color:#fff;opacity:0.65}";
const char CONFIG_JS[] PROGMEM = "!function(){var n=6e4,e=5e3,t=[\"Lamponi is checking your settings.<br/>This can take up to 60 seconds.\",\"Lamponi has connected successfully.<br/>You can now close this page and connect to your usual WiFi again.<br/><br/>Enjoy your Lamponi :)\",\"Lamponi couldn't connect to your Wifi.<br/>Please check your settings and try again.<br/><small>(Click to close this message)</small>\",\"Lamponi ran into an error.<br/>Please refresh the page and try again.\"],o=[\"centered\",\"active\",\"done\",\"open\",\"success\",\"error\",\"hidden\",\"spin\"];function i(n){return document.querySelector(n)}var c=i(\"form\"),a=i(\".logo-container\"),s=i(\".circle-loader\"),r=i(\".btn-refresh\"),u=i(\".overlay\"),l=i(\".text\"),f=i(\".toggleBtn\"),d=i(\".toggleText\"),h=i(\"select\"),g=1,m=0;function b(n){l.innerHTML=t[n]}function p(n,e,t){n.classList.toggle(o[e],t)}function v(n,e){n.addEventListener(\"click\",e)}function y(n){p(u,n?4:5,1),p(s,2,1)}function w(){for(p(r,7,1),h.disabled=!0,r.disabled=!0;h.length;)h.remove(0);fetch(\"/ssids\").then(function(n){if(200===n.status)return n.json();throw null}).catch(function(){window.setTimeout(w,2e3)}).then(function(n){if(n){for(var e in n){var t=document.createElement(\"option\");t.value=n[e],t.text=n[e],h.add(t)}p(r,7,0),h.disabled=!1,r.disabled=!1}})}function L(){if(m>=n)return y(1),void b(1);fetch(\"/ping\").then(function(n){if(200!==n.status)throw null;y(0),b(2)}).catch(function(){m+=e,window.setTimeout(L,e)})}function T(){if(-1!==h.selectedIndex){var n=new FormData(c);p(u,3,1),p(a,0,1),p(s,1,1),b(0),fetch(\"/config\",{method:\"POST\",body:n}).then(function(n){if(200!==n.status)throw null;m=e,window.setTimeout(L,e)}).catch(function(){y(0),b(3)})}}v(r,w),v(f,function(){p(d,6,g=!g)}),v(u,function(){u.classList.contains(o[5])&&(p(a,0,0),p(s,1,0),p(s,2,0),p(u,3,0),p(u,4,0),p(u,5,0))}),c.addEventListener(\"submit\",function(n){n.preventDefault(),T()}),w()}();";
const char CONFIG_HTML[] PROGMEM = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><link rel=\"shortcut icon\" type=\"image/png\" href=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAMAAABEpIrGAAAAk1BMVEUAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB6eSN1AAAAMHRSTlMA+ufM8OsSCPeAax0OlHorGAX04sSzm4dyZD44MiYMAtW/pYx1WUpD2dDJt11V3KqbKhn/AAABGklEQVQ4y4WRW5KCMBBFm5jwBkFAUAEFlPE5c/e/uiE1zIdlWs9Hpyv3VCVdTc84frckHqcScHdsHMYKqyEhSqJbashbAVnaUzy4ODgGIe3jkMguV8g2KfuKJyF8h4vbWEJVU7zf5LVhhKOCitupe5zhbl+FAtILp3NcwFoH9Mrds6e664CfhjiWBXCr2bjpgVw/3lYbQ2xHFi7j/NvcIJT4Pu31iBmkZxuE4JHqTx7gDjax+JYekWeLbEfvyK2awnXDC/JA9IWYzffotOARi7v4IJyvRA18XggSXdhNKeufwiickC3+cFeMUM3dxSyMKOdOCKOQWMLXa6ojFGTkCIiA/KkuuTkiRKmSd37djoTCmt6wvYo+fLr5BeVYFet7hqANAAAAAElFTkSuQmCC\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1,maximum-scale=1\"><meta name=\"theme-color\" content=\"#ff2961\"><title>Lamponi</title><link rel=\"stylesheet\" href=\"app.css\"></head><body><div class=\"logo-spacer\"><div class=\"logo-container\"><img class=\"logo\" src=\"lamponi.svg\"><div class=\"circle-loader\"></div></div></div><form id=\"Form\"><h1>Your WIFI</h1><div class=\"form-group\"><div class=\"input-group\"><select name=\"ssid\" title=\"Your WiFi network\"><option value=\"ssid1\">WLAN 1</option><option value=\"ssid2\">WLAN 2</option></select><button type=\"button\" class=\"btn btn-refresh\"></button></div></div><div class=\"form-group\"><input type=\"text\" name=\"password\" placeholder=\"Your WiFi password\"></div><h1>Your Account</h1><div class=\"form-group\"><input type=\"text\" name=\"username\" placeholder=\"Username\"></div><div class=\"form-group\"><input type=\"password\" name=\"userPassword\" placeholder=\"Password\"></div><button type=\"button\" class=\"toggleBtn\">Advanced Settings</button><div class=\"toggleText hidden\"><div class=\"form-group\"><input type=\"text\" name=\"server\" value=\"lamponi.rocks\" placeholder=\"Server address\"></div></div><button type=\"submit\" class=\"btn btn-submit\">Continue</button></form><div class=\"overlay\"><div class=\"text\"></div></div><script type=\"text/javascript\" src=\"app.js\"></script></body></html>";
const char CONFIG_SVG[] PROGMEM = "<?xml version=\"1.0\" ?><!DOCTYPE svg><svg enable-background=\"new 0 0 91 91\" height=\"91px\" version=\"1.1\" viewBox=\"0 0 91 91\" width=\"91px\" xml:space=\"preserve\" xmlns=\"http://www.w3.org/2000/svg\"><g fill=\"#fff\"><path d=\"M29.392,8.755c-1.246,0.609-1.764,2.113-1.154,3.361c0.436,0.891,1.33,1.408,2.26,1.408 c0.369,0,0.746-0.082,1.102-0.254c1.338-0.654,3.113-1.502,5.082-2.439c3.773-1.797,8.049-3.834,11.516-5.594 c1.238-0.627,1.732-2.139,1.104-3.377c-0.627-1.236-2.141-1.732-3.377-1.104c-3.41,1.73-7.656,3.754-11.404,5.539 C32.534,7.242,30.741,8.095,29.392,8.755z\"/><path d=\"M61.552,32.56c-1.35,0.688-2.684,1.354-4.004,2.016c-4.115,2.057-8,3.998-12.018,6.383 c-9.465,5.613-9.053,10.768-8.303,20.125c0.105,1.314,1.205,2.313,2.502,2.313c0.066,0,0.135-0.004,0.203-0.008 c1.383-0.111,2.414-1.322,2.305-2.705c-0.738-9.201-0.912-11.387,5.857-15.404c3.861-2.291,7.668-4.195,11.699-6.209 c1.334-0.666,2.678-1.34,4.039-2.033c1.236-0.631,1.729-2.145,1.098-3.379C64.302,32.421,62.788,31.929,61.552,32.56z\"/><path d=\"M63.087,17.779c-5.174,2.676-11.246,5.908-17.117,9.035c-6.82,3.631-13.264,7.063-17.934,9.43 c-1.238,0.629-1.732,2.141-1.105,3.377c0.443,0.875,1.326,1.377,2.242,1.377c0.383,0,0.771-0.086,1.135-0.271 c4.717-2.391,11.182-5.834,18.023-9.477c5.859-3.121,11.916-6.346,17.064-9.008c1.232-0.639,1.715-2.154,1.076-3.387 C65.835,17.623,64.319,17.14,63.087,17.779z\"/><path d=\"M28.534,27.474c0.377,0,0.76-0.086,1.119-0.266c3.203-1.598,8.482-4.32,14.074-7.205 c6.295-3.246,12.805-6.602,17.869-9.145c1.238-0.623,1.74-2.133,1.117-3.373s-2.131-1.74-3.373-1.117 c-5.088,2.555-11.609,5.918-17.916,9.17c-5.576,2.875-10.842,5.592-14.016,7.174c-1.24,0.621-1.746,2.129-1.125,3.371 C26.724,26.964,27.612,27.474,28.534,27.474z\"/><path d=\"M52.968,63.178c0.016,0,0.031,0,0.049-0.002c1.387-0.025,2.49-1.172,2.463-2.559c-0.035-1.859-0.035-3.174-0.037-4.492 c-0.002-1.324-0.002-2.652-0.037-4.521c-0.027-1.387-1.191-2.52-2.559-2.465c-1.389,0.025-2.492,1.17-2.465,2.559 c0.033,1.832,0.035,3.133,0.035,4.434c0.002,1.344,0.004,2.684,0.039,4.582C50.483,62.084,51.603,63.178,52.968,63.178z\"/><path d=\"M59.938,65.469H32.835c-1.389,0-2.514,1.125-2.514,2.512v6.535c0,5.311,3.166,8.857,8.152,9.27l0.725,0.76 c0.418,3.859,3.146,6.297,7.186,6.297s6.766-2.438,7.184-6.297l0.725-0.76c4.99-0.41,8.158-3.957,8.158-9.27V67.98 C62.45,66.594,61.325,65.469,59.938,65.469z M57.425,74.516c0,2.883-1.348,4.285-4.121,4.285h-0.125 c-0.686,0-1.344,0.281-1.818,0.777l-2.066,2.168c-0.445,0.467-0.695,1.088-0.695,1.734c0,1.68-0.621,2.336-2.215,2.336 c-1.574,0-2.217-0.678-2.217-2.336c0-0.646-0.25-1.268-0.695-1.734l-2.064-2.166c-0.475-0.498-1.131-0.779-1.818-0.779h-0.121 c-2.773,0-4.121-1.402-4.121-4.285v-4.021h22.078V74.516z\"/></g></svg>";
#endif

// all other configurations will come here
