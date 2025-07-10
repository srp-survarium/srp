int __cdecl _getch_nolock()
{
  int result; // eax
  int AsciiChar; // edi
  const NormKeyVals *v2; // eax
  _INPUT_RECORD ConInpRec; // [esp+4h] [ebp-1Ch] BYREF
  unsigned int oldstate; // [esp+18h] [ebp-8h] BYREF
  unsigned int NumRead; // [esp+1Ch] [ebp-4h] BYREF

  if ( chbuf == -1 )
  {
    if ( _coninpfh == (HANDLE)-2 )
      __initconin();
    if ( _coninpfh == (HANDLE)-1 )
    {
      return -1;
    }
    else
    {
      GetConsoleMode(_coninpfh, &oldstate);
      SetConsoleMode(_coninpfh, 0);
      while ( 1 )
      {
        if ( !ReadConsoleInputA(_coninpfh, &ConInpRec, 1u, &NumRead) || !NumRead )
        {
          AsciiChar = -1;
          goto LABEL_15;
        }
        if ( ConInpRec.EventType == 1 && ConInpRec.Event.KeyEvent.bKeyDown )
        {
          AsciiChar = (unsigned __int8)ConInpRec.Event.KeyEvent.uChar.AsciiChar;
          if ( ConInpRec.Event.KeyEvent.uChar.AsciiChar )
            goto LABEL_15;
          v2 = _getextendedkeycode(&ConInpRec.Event.KeyEvent);
          if ( v2 )
            break;
        }
      }
      AsciiChar = v2->RegChars.LeadChar;
      chbuf = v2->RegChars.SecondChar;
LABEL_15:
      SetConsoleMode(_coninpfh, oldstate);
      return AsciiChar;
    }
  }
  else
  {
    result = (unsigned __int8)chbuf;
    chbuf = -1;
  }
  return result;
}
