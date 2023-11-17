// Wait for the HTML document to be fully loaded before executing the script
document.addEventListener('DOMContentLoaded', function () {
  // Get a reference to the file upload form
  const fileUploadForm = document.getElementById('fileUpload');

  // Add an event listener to the file upload form
  fileUploadForm.addEventListener('submit', async function (event) {
    // Prevent the default form submission
    event.preventDefault();

    // Get references to the upload button and the file input
    const uploadBtn = document.getElementById('uploadBtn');
    const uploadInput = document.getElementById('uploadInput');

    // Update the UI to indicate the uploading process
    uploadBtn.value = 'Uploading...';
    uploadInput.classList.add('disabled');
    uploadBtn.classList.add('disabled');

    // Get the selected file from the file input
    const fileInput = fileUploadForm.querySelector('input[type="file"]');
    const file = fileInput.files[0];

    // Check if a file is selected
    if (file) {
      // Create a FormData object and append the selected file to it
      const formData = new FormData();
      formData.append('file', file);

      // Log the first value in the FormData object
      console.log(formData.values().next());

      // Send a POST request to the server with the file data
      const response = await fetch('/api/upload', {
        method: 'POST',
        body: formData,
      });

      // Check if the upload was successful
      if (response.ok) {
        // Parse the response data as JSON
        const data = await response.json();
        console.log(data.message);

        // Update the response message in the HTML
        document.getElementById('responseMessage').textContent =
          'Upload Successful!';
      }

      // Set a timeout to revert the UI changes after 2 seconds
      setTimeout(() => {
        uploadInput.classList.remove('disabled');
        uploadBtn.classList.remove('disabled');
        uploadBtn.value = 'Upload Now';

        // Clear the file input
        uploadInput.value = '';
        document.getElementById('responseMessage').textContent = '';
      }, 2000);
    } else {
      // File does not exist, show an alert or take appropriate action
      alert('Please select a file before clicking the Upload button.');
    }
  });
});
