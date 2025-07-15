int __fastcall _EH4_TransferToHandler(int (__fastcall *this)(_DWORD, _DWORD), unsigned int a2)
{
  _NLG_Notify((unsigned int)this, a2, 1u);
  return this(0, 0);
}
