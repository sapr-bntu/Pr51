function func() {

}

function openFile()
{
    if (imgapp.RunOpenFile())
    {
        updateImage();
        nextButton.enabled="true";
        prevButton.enabled="true";
    }
}

function updateImage()
{
    image1.source=imgapp.GetCurrentFile();
    image1.sourceSize.width=imgapp.ImageW();
}

function prevFile()
{
    imgapp.MovePrev();
    updateImage();
}

function nextFile()
{
    imgapp.MovePrev();
    updateImage();
}
