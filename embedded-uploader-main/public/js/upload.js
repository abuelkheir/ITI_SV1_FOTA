document.addEventListener('DOMContentLoaded', function () {
  const fileUploadForm = document.getElementById('fileUpload');

  fileUploadForm.addEventListener('submit', async function (event) {
    event.preventDefault(); // Prevent the default form submission
    const uploadBtn = document.getElementById('uploadBtn');
    const uploadInput = document.getElementById('uploadInput');

    uploadBtn.value = 'Uploading...';
    uploadInput.classList.add('disabled');
    uploadBtn.classList.add('disabled');

    const fileInput = fileUploadForm.querySelector('input[type="file"]');
    const file = fileInput.files[0];

    if (file) {
      const formData = new FormData();
      formData.append('file', file);
      // formData.append('weird', 'weird');
      console.log(formData.values().next());
      //
      const response = await fetch('/api/upload', {
        method: 'POST',
        body: formData,
      });
      if (response.ok) {
        const data = await response.json();
        console.log(data.message);
        document.getElementById('responseMessage').textContent =
          'Upload Successful!';
      }

      setTimeout((_) => {
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
