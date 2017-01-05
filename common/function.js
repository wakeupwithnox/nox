function loadJson(url) {
    var request;
    request = new XMLHttpRequest();
    request.open('GET', url, false);
    request.send(null);
    return JSON.parse(request.responseText);
    }