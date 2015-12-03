<!DOCTYPE html>
<html lang="en">
<head>
  <title>iCyber Security Solutions</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
  <script src="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js"></script>
</head>
<body>

<div class="container">
  <h2> iCyber Security Solutions </h2>
  <ul class="nav nav-tabs">
    <li class="active"><a data-toggle="tab" href="#home">Main</a></li>
    <li><a data-toggle="tab" href="#menu1">Why choose us</a></li>
    <li><a data-toggle="tab" href="#menu2">About</a></li>
    <li><a data-toggle="tab" href="#menu3">Help</a></li>
    <li><a data-toggle="tab" href="#menu4">Contact us</a><li>
  </ul>

  <div class="tab-content">
    <div id="home" class="tab-pane fade in active">
      <h2> Welcome </h2>
      <h3> So what is iCyber Security Solutions? </h3>
      <?php
          echo "<p>";
          echo "iCyber Security solutions is a cyber security program, that's it! It offers top notch ";
          echo "security solution for your computer so that you can stay safe on the internet. The ";
          echo "internet is chalk full of dangerous webpages that lurk to threaten your security every day. ";
          echo "With intelligently designed firewalls to deal with external attacks and ruthless ";
          echo "process scanners and sand box executions for suspicious programs, you cannot go wrong by ";
          echo "using our security program or we guarantee your money back!";
          echo "</p>";
      ?>
      <h3> Products </h3>
      <p> We offer the following three product options </p>
      <table border="0">
         <tr>
            <td style="width:300px;">
               <h4 align="Center"> Minimal </h4>
               <p align="Center"> Offers the following support in this edition </p>
               <ul>
                  <li> Minimal firewall </li>
                  <li> Minimal virus protection </li>
                  <li> Cheapest option coming in at $14.95/month </li>
               </ul>
            </td>
            <td style="width:300px;">
               <h4 align="Center"> Extreme </h4>
               <p align="Center"> Offers the following support in this edition </p>
               <ul>
                  <li> Extended firewall </li>
                  <li> Support desk access (you can submit tickets for FREE!) </li>
                  <li> Value option coming in at $34.95/month </li>
               </ul>
            </td>
            <td style="width:300px;">
               <h4 align="Center"> Ultimate </h4>
               <p align="Center"> Offers the following support in this edition </p>
               <ul>
                  <li> Highest level of protection offered (firewall and anti-virus) </li>
                  <li> 24/7 chat and support desk options available </li>
                  <li> Enterprise pricing at $90.00/month </li>
               </ul>
            </td>
         </tr>
      </table>
      <h3> Guarantee </h3>
      <p> As was listed above, we do offer a guarantee that our product works or you will receive a FULL refund! </p>
    </div>
    <div id="menu1" class="tab-pane fade">
      <h3> Why choose us </h3>
      <?php
          echo "<p>";
          echo "Here at iCyber security we understand that when you are choosing security software for ";
          echo "your computer you have many options. So why choose us? The main reason is because ";
          echo "this company's founders are deeply rooted in the world of hacking. Who better to understand ";
          echo "how hackers will try to penetrate your system then hackers themselves! You're probably asking, ";
          echo "why should we trust self professed hackers, how do we know this will work? How do we know that ";
          echo "iCyber Security isn't here just for my money? As mentioned before we guarantee your product ";
          echo "will protect you or you'll get your money back! So there are no scams!";
          echo "</p>";
          echo "<p> Thank you for considering using iCyber Security Solutions! We hope we can do business together.</p>";
      ?>
    </div>
    <div id="menu2" class="tab-pane fade">
      <h3> About </h3>
      <p> Thank you for considering using iCyber security solutions! This page will display information about our product </p>
      <h4> Supported operating systems </h4>
      <p> We support the following operating systems </p>
      <table border="0">
         <tr>
            <td>
               <h4 align="Center"> Linux </h4>
               <img src="linux.png" style="width:200px;">
            </td>
            <td>
               <h4 align="Center"> Windows </h4>
               <img src="windows.png" style="width:200px;">
            </td>
            <td>
               <h4 align="Center"> Mac OSX </h4>
               <img src="mac.png" style="width:200px;">
            </td>
         </tr>
      </table>
    </div>
    <div id="menu3" class="tab-pane fade">
      <h3> Help </h3>
      <h4> Operating iCyber Security </h4>
      <p> Operating our program is very simple. Please take a look at the section for the window that applies to you:</p>
    </div>
    <div id="menu4" class="tab-pane fade">
    <h3> Contact us </h3>
    <p id="error"></p>
    <form action="" method="POST" enctype="multipart/form-data">
       <input type="hidden" name="action" value="submit">
       Your name:<br>
       <input name="name" type="text" value="" size="30"/><br>
       Your email:<br>
       <input name="email" type="text" value="" size="30"/><br>
       Your message:<br>
       <textarea name="message" rows="7" cols="30"></textarea><br>
       <button type="button" onclick="sendEmail()"> Send email </button>
    </form>
    <script>
       function sendEmail() {
          document.getElementById("error").innerHTML = "Sent email";
       }
   </script>
   </div>
  </div>
</div>
</body>
 
</html>
