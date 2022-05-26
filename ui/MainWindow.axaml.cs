using Avalonia.Controls;
using Avalonia.Interactivity;
using System.Collections.Generic;
using System.IO;

namespace FlashProject
{
    public partial class MainWindow : Window
    {
        private List<DriveInfo> drivesList = new List<DriveInfo>();

        public MainWindow()
        {
            InitializeComponent();
            FindDrives();
        }

        private void FindDrives()
        {
            List<ComboBoxItem> drives = new List<ComboBoxItem>();
            var counter = 0;
            foreach (DriveInfo driveInfo in DriveInfo.GetDrives())
            {
                if(driveInfo.DriveType == DriveType.Removable)
                {
                    var t = new ComboBoxItem();
                    t.Content = "["+ counter.ToString() +"] "+ driveInfo.Name;
                    drives.Add(t);
                    counter++;
                    drivesList.Add(driveInfo);
                }
            }
            FlashDrives.Items = drives;
        }

        private void OnStartClick(object sender, RoutedEventArgs e)
        {
            //on start button click
        }
    }
}
