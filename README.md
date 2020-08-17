Welcome to the Github site of UNIX: The Textbook, 3rd edition!
Follow us at Twitter, @unixthetextbook
 
At this GitHub site, you will find In-Chapter Exercise Solutions (as ICE_Ch files), 
weblinks, and errata, all in Word .doc and .pdf formats.
Advisory information will be updated regularly, and will give
important changes in PC-BSD and Solaris since the printing of the book.
You will also find program source code in UNIX-compatible text
format here, so you don't have to type in program listings shown in the
printed book that are more than a few lines long!

If you follow the instructions in the printed book for Example
17.5, you will be able to "pull" everything from this Github site
to a git-enabled directory on your own computer! Alternatively,
you can just download the above-provided materials via a web
browser interface.

The newly revised CRC Press website for this book, where you will find additional
materials for the printed book, is-
https://www.routledge.com/UNIX-The-Textboo-k-Third-Edition/Sarwar-Koretsky/p/book/9780367574352

You can also report any errors you find in the printed book here.
Just email bobk48@gmail.com, and we will evaluate your error reports
or any other requests you make, and take appropriate action.

Advisory 19. Posted 8/17/2020 The newly revised CRC Press website for this book can be found at-

https://www.routledge.com/UNIX-The-Textboo-k-Third-Edition/Sarwar-Koretsky/p/book/9780367574352

Advisory 18. Posted 4/20/2020 There's an excellent online User Guide for PC-BSD 10.3 at the following URL:

http://ftp.icm.edu.pl/packages/pcbsd/iso/10.3-RELEASE/amd64/docs/html/pcbsd.html

Advisory 17. Posted 4/20/2020, edited 4/22/2010 Since PC-BSD and the AppCafe are no longer supported by iXsystems, 
and if you've downloaded our PC-BSD ISO from the GitLab site for this book,
you're going to have to build some of the software we use. For example, we found that the ISO file at the GitLab site didn't have vim pre-loaded.
So to use the book chapter on text editors, and the part of it dealing with vim you have to do this:

You have to use the git command. This is the simplest and most efficient way to obtain the latest version of vim, including all patches. 
The explanations are on the GitHub page, but the following three commands achieve the installation of vim on a UNIX system-

git clone https://github.com/vim/vim.git

cd vim/src

make

Please note that some of the other software we show in the book may also need to be built from source, but at this time we don't have a comprehensive listing of those.
But anywhere in the book we ask you to install software using the AppCafe in PC-BSD, that is a good indication that you will have to install that software on your own,
either from GitHub sites or other online repositories, as we have shown above with vim.

Advisory 16. Posted 4/17/2020 Just some informational news here, osdisc.com is no longer in business. This was a great source for UNIX systems pre-built on a variety of media.
And iXsystems no longer is maintaining or supporting TrueOS, so Advisories 1. & 14. are no longer valid. But you can still download PC-BSD from our GitLab site,
as detailed in Advisories 10. through 13., along with Solaris 11.3!

Advisory 15. Posted 4/13/2020 iXsystems no longer maintains a web site for download of PC-BSD! But fortunately, per Advisory 10. below, you can still obtain versions of PC-BSD from our GitLab repo.

Advisory 14. Posted 8/27/17 After careful consideration, we advise you to not use TrueOS in place of
PC-BSD. There are so many fundamental differences in the GUI's of TrueOS and PC-BSD, that lead to
decreased functionality of the former. We feel this is detrimental to the learning experience of a
novice UNIX desktop user.

Advisory 13. Posted 3/24/17, modified 3/25/17 We have uploaded the VitualBox PCBSD10.2-RELEASE-x64-pcbsd-desktop.ova and the PCBSD10.2-RELEASE-x64-pcbsd-desktop.vdi.xz files to the Gitlab site, for your use with Chapter 25 of the printed book. Both of these files can still be downloaded from pcbsd.org using the instructions given in Chapter 25!

Advisory 12. Posted 3/22/17 Be sure to carefully read the license and checksum files provided at our Gitlab site before you download the ISO images for either PC-BSD 10.3 or Solaris 11.3. This file is named PCBSD_Solaris_Licenses_checksums.
Additionally, in a few days we will be uploading the VirtualBox images for the operating systems listed in Chapter 25 of the printed book. These images will also be covered by the license and checksum file now on the Gitlab site. 

Advisory 11. Posted 3/21/17 We have added the Solaris 11.3 live installation ISO to our Gitlab site repo (as specified in Advisory 10.). It is named sol-11_3-live-x86.iso, and is about 1.2 GB in size, as opposed to the PC-BSD 10.3 ISO which is 3.7 GB. Even though Solaris 11.3 is still available for download from Oracle, if you download our Gitlab ISO and burn it to a DVD, you can accomplish everything shown in the printed book by running Solaris 11.3 from the DVD. Additionally, at the present time, you can install the full Solaris 11.3 from our live ISO image burned to a DVD. Please be aware that the same copyright and licensing restrictions apply to the use of our ISO image as to the Oracle-downloaded ISO image!

Advisory 10. Posted 3/20/17 We have established a Gitlab repo at https://gitlab.com/bobk48/pcbsd103iso that contains the ISO image for PC-BSD 10.3. The ISO image, suitable for burning to a DVD, is named PCBSD10.3-RELEASE-03-31-2016-x64-DVD.iso. In case iXsystems no longer supports pcbsd.org and that image is no longer availble from them, you can use your web browser to navigate to our Gitlab repo, and download the ISO image from there! In the near future, we may also make a VirtualBox image of PC-BSD 10.2 available for use with Chapter 25 of the printed book. And if Solaris 11.3 (or whatever follows that release) is no longer supported by Oracle for downloading, we will make that ISO image available so that the material dealing with Solaris UNIX in the printed book can be used on your own version of Solaris 11.3. Certain copyright and license restrictions may apply, and we will notify you of these constraints as they become known to us.

Advisory 9. RePosted 8/27/17 See Advisory 14.
Oracle Solaris 11.3 is still active, downloadable, and everything in the printed book still works in Solaris 11.3!

Advisory 8. Posted 3/18/17 We have posted a preliminary Xlib data structure file, in both Word .doc and Adobe .pdf formats, and named Xlib_data_structures. We will be adding material to it in the future to include X Event structures.

Advisory 7. Posted 3/5/17 Look for an Xlib data structures help guide to be published here in a few days. This will be a useful addition to your documentation for Chapter 22 Xlib programming.

Advisory 6. Posted 2/21/17
To help you with XCB programming in Chapter 22, we have put a Word document, xcb_functions.doc, on this Github site. It contains an alphabetized listing of all of the XCB Core API functions, and all other functions, in a format that you can easily search through with the OfficeLibre or Word find facilities. At the top of the document, there is also a prototype function description that shows how all of the function information is presented.

Advisory 5. Posted 12/5/16
Added all the Figures in Chapter 3 as .jpegs, which should give you the ability
to see them more clearly than they appear in the printed book.

Advisory 4. Posted 11/20/16
Added a couple more errors I found to the Errata files! 

Advisory 3. Posted 10/30/16
We have updated the unixthetextbook3 repository so that it contains
both Word .doc and .pdf format files for everything except the
program source code, and this README.md file.

Advisory 2. Posted 10/22/16
Figure 23.16 in the printed book is now available in the ch23 folder
on this Github site. It is in a much larger format, and more readable
here than in the printed book. If there are any other figures in the
printed book that you would like to see here on this Github site, just
let us know by emailing the author at the email address shown above,
and we will try to put those figures as .jpegs in the appropriate
chapter on this site for downloading.

Advisory 1. Posted 10/19/16
PC-BSD has been "re-branded" TrueOS, but all of the material in the
printed book still works perfectly well. That's because, at this time, 
PC-BSD 10.3's(and earlier releases) website is still up and running.
If and when PC-BSD is replaced by TrueOS (probably not within the short
term, if their Forums commentary is any indication), we will notify you 
here at this Github site. 
TrueOS will be developed to the point where it is a one-for-one
replacement for the PC-BSD Desktop version, with of course some enhancements
not shown in the printed book. At that time we will post information
about those enhancements, and how they critically affect the content of
the 3rd edition. In the meanwhile-
Keep your eyes on the errata page (posted here as a Word .doc file), 
and any other Advisories we show here.

Last revised 8/17/2020
