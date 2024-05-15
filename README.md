<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Image Processing Project README</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
        }
        h1, h2 {
            color: #333;
        }
        ol {
            list-style-type: decimal;
            margin-left: 20px;
        }
        li {
            margin-bottom: 10px;
        }
        pre {
            background-color: #f4f4f4;
            padding: 10px;
            border-radius: 5px;
            overflow-x: auto;
        }
    </style>
</head>
<body>
    <header>
        <h1>Image Processing Project</h1>
    </header>
    <section id="about">
        <h2>About</h2>
        <p>The project is about implementing parts of an image-processing web app. Below are the features implemented:</p>
        <ol>
            <li>Brightness - Ananthakrishna K (IMT2022086)</li>
            <li>Contrast - Kandarp Dave (IMT2022115)</li>
            <li>Dominant Colour - Kandarp Dave (IMT2022115)</li>
            <li>Flip - Shreyas S (IMT2022078)</li>
            <li>Gaussian Blur - Aaryan Ajith Dev (IMT2022038)</li>
            <li>Grayscale - Prateek Rath (IMT2022017)</li>
            <li>Hue Saturation - Aaryan Ajith Dev (IMT2022038)</li>
            <li>Invert - Shreyas S (IMT2022078)</li>
            <li>Rotation - Ananthakrishna K (IMT2022086)</li>
            <li>Sepia - Ananthakrishna K (IMT2022086)</li>
            <li>Sharpen - Aaryan Ajith Dev (IMT2022038)</li>
        </ol>
        <p>Note: The exact algorithms or descriptions of the CPP files are written as comments within them. This README provides an overview of various parts of the project.</p>
    </section>
    <section id="functionality">
        <h2>Functionality</h2>
        <p>Most of the work is done in the <code>ImageEffectBackend/src</code> directory. There are 3 directories under the <code>src</code> directory:</p>
        <ol>
            <li>The <code>libraries</code> directory:</li>
            <li>The <code>main</code> directory:</li>
            <li>The <code>service</code> directory:</li>
        </ol>
        <!-- Include detailed descriptions of each directory -->
    </section>
    <section id="setup">
        <h2>Setup</h2>
        <ol>
            <li>In the root directory, run the command: <code>npm i</code></li>
            <li>In the <code>ImageEffectFrontend</code> directory, run the command: <code>npm i</code></li>
            <li>Start the frontend with the command: <code>npm start</code> in the <code>ImageEffectFrontend</code> directory.</li>
            <li>Go to the <code>ImageEffectBackend</code> directory and run the following commands:</li>
            <ol type="a">
                <li><code>make clean</code></li>
                <li><code>make</code></li>
                <li><code>mvn clean package</code></li>
            </ol>
            <li>To start the backend, run the command:</li>
            <pre>java -jar target/imageEffectApplication-0.0.1-SNAPSHOT.jar</pre>
            <li>The website can be accessed at <code>localhost:4200</code>.</li>
        </ol>
    </section>
</body>
</html>
