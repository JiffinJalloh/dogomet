 
 
 // copy the following code to app.js 
  var db1 = new PouchDB('Alhaji_Database');
  var remoteCouch = false;
 
 function addTodo(content) 
  {
  var insertIndatabase = {
	  _id: new Date().toGMTString(),
	  title: content,
	  completed: false
  };
      db1.put( insertIndatabase, function(error, inputData)
	  {
		  if (error)
		  {
			  console.log(error);
			  console.log('The above error occur during execution!!!')
		  }else
		  {   console.log('You Entered the following :' + content);
			  console.log('It has been successfully saved in the database');
			  console.log('Thanks that is cool');
		  }
	  });
        
  }
  