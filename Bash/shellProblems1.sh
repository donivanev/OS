: '
• Изведете списък с файловете в текущата директория. Изведете редовете от hello.c и second.c, които съдържат символния низ int. 
'

ls –l
grep int hello.c second.c

: '
• Извежда списък на файловете с текущата директория сортирани по време на създаване. 
Разпечатва съдържанието  на екрана на тези два от тях, които са с най-малък размер в байтове, прави ги с пълни права 
на достъп за собственика, четене и писане на групата, само четене на всички останали. Създава нова директория FIRST. 
Прави две копия на единия от тях – f1 и f2 в току-що създадената директория. Изтрива първичния файл./
'

ls –t
ls –lSr | grep '^-' | head –n 2
cat $(ls -lSr | grep '^-' | head -n 2 | tr -s ' ' | cut -f9- -d ' ')
su chmod 764 f1 f2 
mkdir FIRST
cp f f1 f2
rm f

: '
• Изведете в обратен ред по времето на създаване само файловете от текущата директория, чийто имена започват с f 
и завършват на .с. Изведете правата за достъп  на всеки файл и ги запишете в друг файл. 
'

ls –tr | find . –name f*.c
ls –l | grep '^-' | cut –c 1-11 > permissions

: '
• Изведете броя на файловете в текущата директория, с права на достъп 644 и отпечатайте само имената им.
'

ls –l | grep -- -rw-r--r-- | tr –s ' ' | cut –f9- -d ' '

: '
• От стандартния вход се въвеждат три имена на файлове. Във файла – len извеждате броя на буквите в името им, 
а във файла size – размера им в байтове.
'

read f1 f2 f3
a=$(expr length $f1); b=$(expr length $f2); c=$(expr length $f3)
echo $f1 $f2 $f3 > len
echo $f1 > temp; wc –c < temp > size
echo $f2 > temp2; wc –c < temp2 >> size
echo $f3 > temp3; wc –c < temp3 >> size

: '
• Да се състави командна процедура, която получава като параметри в командния ред име на файл и символен низ.  
Създайте 3 копия на подадения  файл, разпечатайте редовете, в които се среща подадения символен низ в този файл и 
изведете техния брой във файл, чието име се подава от стандартния вход. 
Преместете файла в поддиректория info в родителската директория на началната потребителска директория.
'

set f1 str
tee f1 f2 f3 < $1
grep $2 cat $1
read f4;
grep $2 $1 | wc –l > $f4
mv $1 $HOME/../info

: '
• Да се състави командна процедура, която получава като параметри в командния ред имена на съществуващи текстови файлове. 
Прочита от стандартния вход символен низ и за всеки от зададените файлове извежда по подходящ начин на стандартния изход 
броя на редовете които съдържат низа.
'

set f1 f2
read str
grep $str $1 | wc –l 
grep $str $2 | wc –l 
for i 
do 
  echo $i
  grep $str $i | wc –l
done

: '
• Да се състави командна процедура, която получава като параметри в командния ред име на директория и акаунт на потребител.
Процедурата намира общия размер на всички файлове в подадената директория и изпраща получената информация на потребителя с 
подадения акаунт, в случай че той е стартирал сесия.
'

c=0
list=$(find $1 -type f -exec wc -l {} \; | cut -d ' ' -f1)
for i in $list
do 
  c=$(expr $i + $c)
done 
echo $c
if who | grep $2 > /dev/null
then 
    echo $c | write $2
fi
