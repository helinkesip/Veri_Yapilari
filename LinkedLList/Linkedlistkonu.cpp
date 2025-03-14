/*1. Root (Kök) Nedir?
Root, genellikle baðlý listenin ilk düðümünü (node) ifade etmek için kullanýlan bir terimdir.
Dinamik veri yapýlarýnda, özellikle aðaçlarda (tree) root daha yaygýn bir kavramdýr, ancak baðlý listelerde de ilk düðüm olarak kullanýlabilir.
Root düðümü, listenin baþlangýcýný temsil ettiði için bütün listeye eriþim bu düðüm üzerinden saðlanýr.
Örnek:
Baðlý listenin baþlangýç durumu þu þekilde olsun:
?? Root ? 10 ? 20 ? 30 ? NULL
Burada root, 10’u gösteren düðümdür ve eðer root’u kaybedersek, tüm listeyi kaybederiz.

2. Iter (Ýteratör) Nedir?
iter, baðlý listeyi gezmek için kullanýlan bir iþaretçidir.
Root düðümünden baþlayarak listenin her elemanýna tek tek ulaþmak için kullanýlýr.
Her adýmda bir sonraki düðüme ilerler.
Nasýl Kullanýlýr?
Baþlangýç olarak iter, root’a eþitlenir.
Bir döngü içinde iter sürekli güncellenerek listenin sonuna kadar ilerletilir.


?? root->next, root’un iþaret ettiði düðümün bir sonraki düðümü gösteren pointer’ýdýr.

Baðlý listelerde her düðüm, kendi verisini (data) ve bir sonraki düðümün adresini (next) tutar. 
Yani her düðüm, kendisinden sonra gelen düðümün adresini gösteren bir pointer içerir.


neden rootu hep kullanmýyoruz da iterden yardým alýyoruz?

--root pointer'ý, baðlý listenin baþlangýç düðümünü (ilk düðümü) iþaret eder. Bu düðüm, listenin baþlangýcýný temsil eder ve
listenin yapýsýný korumak için önemlidir. Eðer root üzerinde doðrudan iþlem yaparsak (örneðin, root = root->next gibi), baðlý
listenin baþlangýç düðümünü kaybedebiliriz. Bu durumda, listenin geri kalanýna eriþimimiz tamamen kaybolur ve bellek sýzýntýlarýna 
neden olabilir.
Bu nedenle, baðlý listede gezinmek veya iþlem yapmak için genellikle geçici bir pointer (iter gibi) kullanýrýz. Bu geçici pointer, 
listenin baþlangýcýný (root) iþaret eder ve listenin üzerinde gezinebilir. Bu þekilde, root deðiþmez ve listenin baþlangýcýný her zaman 
koruruz.


---root, listenin baþlangýcýný temsil eder ve deðiþtirilmemelidir.

---iter gibi geçici bir pointer, listenin üzerinde gezinmek ve iþlem yapmak için kullanýlýr.

*Bu yaklaþým, listenin yapýsýný korur ve kodun daha modüler ve okunabilir olmasýný saðlar.




































*/