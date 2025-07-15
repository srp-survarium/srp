int __usercall Wm4::HullEdge2<float>::GetSign@<eax>(
        Wm4::HullEdge2<float> *this@<esi>,
        int i@<eax>,
        Wm4::Query2<float> *pkQuery@<ecx>)
{
  int v4; // [esp-4h] [ebp-4h]

  if ( i != this->Time )
  {
    v4 = this->V[1];
    this->Time = i;
    this->Sign = pkQuery->ToLine(pkQuery, i, this->V[0], v4);
  }
  return this->Sign;
}
