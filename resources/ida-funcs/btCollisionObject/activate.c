void __fastcall btCollisionObject::activate(btCollisionObject *this, int a2)
{
  int v2; // edx

  if ( (*(_BYTE *)(a2 + 216) & 3) == 0 )
  {
    btCollisionObject::setActivationState(this, a2, 1);
    *(_DWORD *)(v2 + 232) = 0;
  }
}
