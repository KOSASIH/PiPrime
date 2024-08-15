package main

import (
	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/app"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/widget"
)

func main() {
	a := app.New()
	w := a.NewWindow("GUI")

	initButton := widget.NewButton("Init", func() {
		// initialization code here
	})
	runButton := widget.NewButton("Run", func() {
		// running code here
	})
	stopButton := widget.NewButton("Stop", func() {
		// stopping code here
	})
	statusButton := widget.NewButton("Status", func() {
		// status code here
	})

	w.SetContent(container.NewVBox(
		initButton,
		runButton,
		stopButton,
		statusButton,
	))

	w.ShowAndRun()
}
