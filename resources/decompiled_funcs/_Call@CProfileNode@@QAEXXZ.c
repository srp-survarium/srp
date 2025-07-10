void __usercall CProfileNode::Call(CProfileNode *this@<ecx>, _DWORD *a2@<esi>)
{
  int v2; // eax

  v2 = a2[4];
  ++a2[1];
  a2[4] = v2 + 1;
  if ( !v2 )
    a2[3] = btClock::getTimeMicroseconds((btClock *)1);
}
