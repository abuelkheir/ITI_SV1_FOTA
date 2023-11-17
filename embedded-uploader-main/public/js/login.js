// Wait for the HTML document to be fully loaded before executing the script
document.addEventListener('DOMContentLoaded', function () {
  
  // Add an event listener to the login form
  document.getElementById('loginForm').addEventListener('submit', function (event) {
    
    // Prevent the default form submission behavior
    event.preventDefault();
    
    // Get references to the username and password input fields
    const usernameInput = document.getElementById('login__username');
    const passwordInput = document.getElementById('login__password');

    // Check if the entered username and password match "ahmed"
    if (usernameInput.value.trim() === 'ahmed' && passwordInput.value.trim() === 'ahmed') {
      
      // Successful login, display an alert
      alert('Login successful!');
      
      // Delay the redirection to another file by 3 seconds
      setTimeout(function () {
        // Redirect to another HTML file (replace 'UploadPage.html' with the desired file name)
        window.location.href = 'UploadPage.html';
      }, 3000);
    } else {
      
      // Invalid login, display an alert
      alert('Invalid username or password.');
      
      // Prevent the form submission
      event.preventDefault();
    }
  });
});
