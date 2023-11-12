# Ieva-MarijaDM2-1.1 1.0
Vartotojui yra pateikiamas pasirinkimas - surašyti duomenis rankiniu būdu arba nuskaityti duomenis iš failo:
1) Pasirinkus ranka: įvedamas norimas studentų kiekis ir tada tiek kartų atitinkamai programa prašys vartotojo įvesti šiuos duomenis apie studentą: vardą pavardę, duos pasirinkimą suvesti studento pažymius bei egzamino rezultatą pačiam arba juos leisti sugeneruoti programai. Tada programa apskaičiuos kiekvieno studento galutinį balą pagal vidurkį bei pagal medianą. Rezultatai rūšiuojami pagal studentų pavardes.
2) Pasirinkus nuskaityti: Programa duoda pasirinkimą: nuskaityti iš anksto paruoštus failus ar sugeneruoti juos šią akimirką. Pasirinkus generavimą duodamas list arba vector konteinerių pasirinkimas ir tada programa sukuria atitinkamai su pasirinktu konteineriu 5 skirtingus failus, kuriems sugeneruoja atitinkamai 1000, 10000, 100000, 1000000 ir 10000000 įrašų. Tada kiekvieną iš šių failų ji surūšiuoja pagal esančias pavardes didėjimo tvarka. Visi šie įrašai yra išsaugomi failuose s_1000.txt, s_10000.txt, ... .(*) Tai atlikusi programa imasi duomenų išskaidymo į dar du failus: lygina stulpelyje "galutinis(vid.)" esančius duomenis ir juos išskaido į "vargšiukus" arba "kietiakius", priklausomai nuo galutinio balo dydžio - vargšiukai yra tie, kurių g.b. yra mažesnis nei 5, o kietiakai yra tie, kuriu g.b. yra didesnis arba lygus 5. Šie procesai taikomi atitinkamai kiekvienam sugeneruotam failui. Galiausiai mes skaičiuojame programos veikimo laiką - kiek užtrunka mus dominanti funkcija. Sukame ciklą - leidžiame funkcijas 5 kartus ir jų veikimo laiką imame vidurkį šių 5kartų, kad duomenys būtų tikslesni. Pasirinkus iš anksto sugeneruotus failus, programa atlieka darbą nuo ( *). 
3) Šios programos tikslas yra ištirti 3 skirtingų strategijų rušiavimo funkcijoje veikimo laiką.
  3.1) 1 strategija - tai strategija, su kuria dirbome v0.3 versijoje. Šioje strategijoje studentų vektorių dalinome į du vektorius: vargšiukus bei kietiakus pagal jų mokymosi rezultatus. Taip buvo sukuriami du nauji vektoriai, o studentų vektorius išlikdavo nepakitęs. Programos vykdymo laikas: ![vector1strategija](https://github.com/ieva-marija/Ieva-MarijaDM2-1.1/assets/144428382/f906df9f-e71e-4dab-b70e-dcce3ef82a38)
   
  3.2) 2 strategija - tai strategija, kurioje studentų vektorių padalinome į dvi dalis - vargšiukus ir kietiakus, bet skirtingai nei 1-oje strategijoje, mes sukūrėme tik vieną papildomą vektorių vargšiukams, o kietiakams jo nebekūrėme. Su remove_if algoritmo pagalba mes atsirinkome vargšiukus, juos perkelėme į vargšiukų vektorių bei ištrynėme iš studentų vektoriaus. Studentų vektoriuje pasiliko tik kietiakai ir tolimesniems veiksmams, susijusiems su kietiakais, naudojamas tiesiog studentų vektorius. Pastebime, kad 2 strategijoje rūšiavimo laikas yra mažesnis lyginant su 1-ąja. Programos vykdymo laikas: ![2strategijoskonsole](https://github.com/ieva-marija/Ieva-MarijaDM2-1.1/assets/144428382/f027e682-a43e-472a-9cf5-b9f53b9f383d)
  
  3.3) 3 strategija - ši strategija yra dar spartesnė nei 2-oji strategija ir automatiškai nei 1-oji. Šioje strategijoje rūšiavimo principas yra kaip ir 2-oje strategijoje: vargšiukai išskirstomi į naują vektorių, o kietiakai pasilieka studentų vektoriuje. 3-ioji strategija nuo 2-osios strategijos skiriasi tik savo rūšiavimo funkcijomis rusiavimas2Vector bei rusiavimas2List. Jose panaudojami du programos veikimą spartinantys algoritmai: remove_copy_if bei remove_if. Tai sparčiausia strategija, jos vykdymo laikas: ![3strategijoskonsole](https://github.com/ieva-marija/Ieva-MarijaDM2-1.1/assets/144428382/bfd51890-9db6-4127-94f6-f67d5c5dbb5f)

Testavimo sistemos parametrai: Procesorius: 4CPUs, ~2.5GHz, Atmintis: 8192MB RAM (7568 naudojama), SSD 
