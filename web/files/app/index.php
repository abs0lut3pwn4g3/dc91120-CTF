<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Files</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
        .uploadbox{
            width: 50%;
            margin: auto;
            text-align: center;
            margin-top: 15%;
        }

        .heading{
            font-size: 2.5em;
        }

    </style>
</head>
<body>
    <div class="uploadbox">
        <div class="heading">
            <h3>FILE VAULT</h3>
        </div>
        <div class="uploadform">
            <form action="/upload.php" method="POST" enctype="multipart/form-data">
                <input type="file" name="image" id="imageUploadInput"/>
                <input type="submit" value="upload" name="upload"/>
            </form>
        </div>
    </div>
</body>
</html>