int TTree_simpleN(Int_t N=1) {
  Int_t det;
  Float_t energy , time;
  
  //TFile f("ttree_simple.root", "RECREATE");
  TFile f(Form("myrootfiles/ttree_simple_%1i.root",N), "RECREATE");

  TTree t ("tree", "My tree");
  t.Branch ("Det" , &det, "det/I");
  t.Branch ("En" , &energy, "energy/F");
  t.Branch ("Time", &time , "time/F");
  
  TRandom3 r;
  r.SetSeed ();
  
  for (int i = 0; i < 100; i++) {
    det = r.Integer (24);
    time = r.Rndm() * 20.;
    energy = r.Rndm() * 30.;
    t.Fill();
  }

  t.Write ();
  return 0;
}
