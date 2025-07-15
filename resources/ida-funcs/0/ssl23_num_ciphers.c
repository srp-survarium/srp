int __cdecl ssl23_num_ciphers()
{
  int v0; // esi
  Scaleform::GFx::AS2::ArrayObject *v1; // ecx

  v0 = ssl3_num_ciphers();
  return v0 + ssl2_num_ciphers(v1);
}
