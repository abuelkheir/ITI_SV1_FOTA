document.addEventListener('DOMContentLoaded', function () {
  document
    .getElementById('loginForm')
    .addEventListener('submit', function (event) {
      event.preventDefault();
      const usernameInput = document.getElementById('login__username');
      const passwordInput = document.getElementById('login__password');

      // Check if the username and password match "ahmed"
      if (
        usernameInput.value.trim() === 'ahmed' &&
        passwordInput.value.trim() === 'ahmed'
      ) {
        // Successful login
        alert('Login successful!');
        // event.preventDefault();

        setTimeout(function () {
          // Navigate to another file after a 3-second delay
          window.location.href = 'UploadPage.html'; // Replace with the desired file name
        }, 1000);
      } else {
        // Invalid login, display an alert
        alert('Invalid username or password.');
        event.preventDefault(); // Prevent form submission
      }
    });
});
