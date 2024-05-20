<body>
    <header>
        <h1>Image Processing Project</h1>
    </header>
    <section id="about">
        <h2>About</h2>
        <p>The project is about implementing parts of an image-processing web app. Below are the features implemented:</p>
        <ol>
            <li>Brightness - Ananthakrishna K</li>
            <li>Contrast - Kandarp Dave</li>
            <li>Dominant Colour - Kandarp Dave</li>
            <li>Flip - Shreyas S</li>
            <li>Gaussian Blur - Aaryan Ajith Dev</li>
            <li>Grayscale - Prateek Rath</li>
            <li>Hue Saturation - Aaryan Ajith Dev</li>
            <li>Invert - Shreyas S </li>
            <li>Rotation - Ananthakrishna K</li>
            <li>Sepia - Ananthakrishna K </li>
            <li>Sharpen - Aaryan Ajith Dev</li>
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
