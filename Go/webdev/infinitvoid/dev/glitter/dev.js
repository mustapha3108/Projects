import './dev.css'
import 'htmx.org';
import Alpine from 'alpinejs'
window.Alpine = Alpine
Alpine.start()

console.log("fuck")

document.addEventListener("htmx:configRequest", (e) => {
    const token = document.cookie
        .split("; ")
        .find(r => r.startsWith("csrf_="))
        ?.split("=")[1];
    if (token) e.detail.headers["X-Csrf-Token"] = token;
});

/*
<button @click="fetch('/apitest', {
        method: 'POST', headers: {'Content-Type': 'application/json', 'X-Csrf-Token': document.cookie.split('; ').find(r => r.startsWith('csrf_='))?.split('=')[1]},
        body: JSON.stringify({message:colab2})
        }).then(r=>r.text()).then(v => {colab2 = parseInt(v); crow = !crow})"
        class="btn btn-accent">test api fetch</button>
*/