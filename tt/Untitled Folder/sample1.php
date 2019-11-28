<table cellspacing="25" border="1px">
<?php
$file_handle = fopen("csIsem.txt", "rb");
error_reporting(E_ALL ^ E_NOTICE);
while (!feof($file_handle) ) {
    $line_of_text = fgets($file_handle);
    $parts = explode(' ', $line_of_text);
    echo "<tr><td>$parts[0]</td>
<td>$parts[1]</td>
<td>$parts[2]</td>
<td>$parts[3]</td>
<td>$parts[4]</td>
<td>$parts[5]</td>
<td>$parts[6]</td>
<td>$parts[7]</td>
<td>$parts[8]</td>
<td>$parts[9]</td>
</tr>";
}
fclose($file_handle);
?>
</table>
