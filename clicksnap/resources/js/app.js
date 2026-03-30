import './bootstrap';
//import Alpine from 'alpinejs'
//window.Alpine = Alpine
//Alpine.start()

document.addEventListener('DOMContentLoaded', function() {
    const hellDivs = document.querySelectorAll('.hell-download');
    
    hellDivs.forEach(function(div) {
        div.addEventListener('click', function() {
            const path = this.dataset.path;
            const title = this.dataset.title;
            
            console.log('Hell clicked! Path:', path, 'Title:', title);
            
            downloadFile(path, title);
        });
    });
});



window.downloadFile = async function (path, title) {
    try {
        const response = await fetch(`/download/${title}/${path}`, {
            method: 'GET',
        });
        
        if (!response.ok) throw new Error('Failed to download');
        
        const blob = await response.blob();
        const url = window.URL.createObjectURL(blob);
        const a = document.createElement('a');
        a.href = url;
        a.download = title;
        document.body.appendChild(a);
        a.click();
        a.remove();
        window.URL.revokeObjectURL(url);
    } catch (e) {
        console.error(e);
        alert('Download failed: ' + e.message);
    }
}
//?path=${encodeURIComponent(path)}&title=${encodeURIComponent(title)}



document.addEventListener('DOMContentLoaded', () => {
    // Only run on the mypics page
    if (!window.location.pathname.includes('mypics')) return;

    const seenIds = new Set();

    // Select all elements with an ID
    document.querySelectorAll('[id]').forEach(el => {
        const id = el.id;

        if (seenIds.has(id)) {
            // Remove duplicates
            el.remove();
        } else {
            seenIds.add(id);
        }
    });

    console.log('Duplicate elements removed!');
});