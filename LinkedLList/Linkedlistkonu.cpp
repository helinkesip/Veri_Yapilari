/*1. Root (K�k) Nedir?
Root, genellikle ba�l� listenin ilk d���m�n� (node) ifade etmek i�in kullan�lan bir terimdir.
Dinamik veri yap�lar�nda, �zellikle a�a�larda (tree) root daha yayg�n bir kavramd�r, ancak ba�l� listelerde de ilk d���m olarak kullan�labilir.
Root d���m�, listenin ba�lang�c�n� temsil etti�i i�in b�t�n listeye eri�im bu d���m �zerinden sa�lan�r.
�rnek:
Ba�l� listenin ba�lang�� durumu �u �ekilde olsun:
?? Root ? 10 ? 20 ? 30 ? NULL
Burada root, 10�u g�steren d���md�r ve e�er root�u kaybedersek, t�m listeyi kaybederiz.

2. Iter (�terat�r) Nedir?
iter, ba�l� listeyi gezmek i�in kullan�lan bir i�aret�idir.
Root d���m�nden ba�layarak listenin her eleman�na tek tek ula�mak i�in kullan�l�r.
Her ad�mda bir sonraki d���me ilerler.
Nas�l Kullan�l�r?
Ba�lang�� olarak iter, root�a e�itlenir.
Bir d�ng� i�inde iter s�rekli g�ncellenerek listenin sonuna kadar ilerletilir.


?? root->next, root�un i�aret etti�i d���m�n bir sonraki d���m� g�steren pointer��d�r.

Ba�l� listelerde her d���m, kendi verisini (data) ve bir sonraki d���m�n adresini (next) tutar. 
Yani her d���m, kendisinden sonra gelen d���m�n adresini g�steren bir pointer i�erir.


neden rootu hep kullanm�yoruz da iterden yard�m al�yoruz?

--root pointer'�, ba�l� listenin ba�lang�� d���m�n� (ilk d���m�) i�aret eder. Bu d���m, listenin ba�lang�c�n� temsil eder ve
listenin yap�s�n� korumak i�in �nemlidir. E�er root �zerinde do�rudan i�lem yaparsak (�rne�in, root = root->next gibi), ba�l�
listenin ba�lang�� d���m�n� kaybedebiliriz. Bu durumda, listenin geri kalan�na eri�imimiz tamamen kaybolur ve bellek s�z�nt�lar�na 
neden olabilir.
Bu nedenle, ba�l� listede gezinmek veya i�lem yapmak i�in genellikle ge�ici bir pointer (iter gibi) kullan�r�z. Bu ge�ici pointer, 
listenin ba�lang�c�n� (root) i�aret eder ve listenin �zerinde gezinebilir. Bu �ekilde, root de�i�mez ve listenin ba�lang�c�n� her zaman 
koruruz.


---root, listenin ba�lang�c�n� temsil eder ve de�i�tirilmemelidir.

---iter gibi ge�ici bir pointer, listenin �zerinde gezinmek ve i�lem yapmak i�in kullan�l�r.

*Bu yakla��m, listenin yap�s�n� korur ve kodun daha mod�ler ve okunabilir olmas�n� sa�lar.




































*/