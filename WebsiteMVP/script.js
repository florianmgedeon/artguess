function changeColor() {
    var buttons = document.getElementsByClassName('price-btn');
    for (var i = 0; i < buttons.length; i++) {
        buttons[i].style.backgroundColor = i == 2 ? 'green' : 'red';
    }
}
