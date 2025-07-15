void __fastcall survarium::intermediate_shared_statistics::clear(
        survarium::intermediate_shared_statistics *this,
        int a2)
{
  memset((void *)a2, 0, 0x50u);
  memset((void *)(a2 + 80), 0, 0x50u);
  *(_DWORD *)(a2 + 160) = 0;
  *(_BYTE *)(a2 + 164) = -1;
}
