function startPost(vencedor, perdedor) {
    var body = {
        vencedor: vencedor,
        perdedor: perdedor
    }

    var post = JSON.stringify(body)

    const url = "/"
    var xml = new XMLHttpRequest()

    xml.open("POST", url, true)
    xml.setRequestHeader("content-type", "application/json; charset = UTF-8");
    xml.send(post);

    xml.onload = () => {
        if (xhr.status === 201) {
            console.log("Post criado!")
        }
    }


}
