curl -s -X POST \
	"http://localhost:8080/person/save?name=Ace" &&
	curl -s -X POST \
		"http://localhost:8080/person/save?name=Luffy" &&
	sleep 1 &&
	curl localhost:8080/person/find/all
