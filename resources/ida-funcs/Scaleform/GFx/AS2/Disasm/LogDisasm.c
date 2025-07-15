void __thiscall Scaleform::GFx::AS2::Disasm::LogDisasm(
        Scaleform::GFx::AS2::Disasm *this,
        const unsigned __int8 *InstructionData)
{
  Scaleform::GFx::AS2::Disasm::LogDisasm::__l2::GASInstInfo *v4; // ebx
  Scaleform::GFx::AS2::Disasm::LogDisasm::__l2::GASInstInfo *i; // eax
  int ArgFormat; // esi
  int v7; // ebx
  int v8; // esi
  int j; // esi
  int v10; // eax
  int v11; // esi
  int v12; // ebx
  unsigned __int8 k; // al
  double v14; // st7
  int v15; // ebx
  int v16; // esi
  unsigned __int8 v17; // al
  unsigned int v18; // eax
  int v19; // ebx
  unsigned int v20; // esi
  unsigned int v21; // eax
  int v22; // esi
  int v23; // edx
  int v24; // esi
  const unsigned __int8 *v25; // eax
  int v26; // ebx
  int v27; // [esp-10h] [ebp-34h]
  int v28; // [esp+4h] [ebp-20h]
  int v29; // [esp+4h] [ebp-20h]
  int v30; // [esp+4h] [ebp-20h]
  int v31; // [esp+4h] [ebp-20h]
  int v32; // [esp+4h] [ebp-20h]
  const char *v33; // [esp+4h] [ebp-20h]
  const char *v34; // [esp+4h] [ebp-20h]
  int v35; // [esp+18h] [ebp-Ch]
  double v36; // [esp+1Ch] [ebp-8h]
  int v37; // [esp+1Ch] [ebp-8h]
  int v38; // [esp+28h] [ebp+4h]
  int v39; // [esp+28h] [ebp+4h]
  int m; // [esp+28h] [ebp+4h]
  int n; // [esp+28h] [ebp+4h]

  v38 = *InstructionData;
  v4 = 0;
  for ( i = InstructionTable; ; ++i )
  {
    if ( i->actionId == v38 )
      v4 = i;
    if ( !i->actionId )
      break;
  }
  ArgFormat = 2;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Disasm::LogF(this, "%-15s", v4->Instruction);
    ArgFormat = v4->ArgFormat;
  }
  else
  {
    Scaleform::GFx::AS2::Disasm::LogF(this, "<unknown>[0x%02X]", v38);
  }
  if ( (v38 & 0x80u) == 0 )
    goto LABEL_13;
  v7 = *(unsigned __int16 *)(InstructionData + 1);
  v39 = v7;
  if ( ArgFormat == 2 )
  {
    v8 = 0;
    if ( *(_WORD *)(InstructionData + 1) )
    {
      do
        Scaleform::GFx::AS2::Disasm::LogF(this, " 0x%02X", InstructionData[v8++ + 3]);
      while ( v8 < v7 );
    }
LABEL_13:
    Scaleform::GFx::AS2::Disasm::LogF(this, "\n");
    return;
  }
  if ( ArgFormat == 1 )
  {
    Scaleform::GFx::AS2::Disasm::LogF(this, " \"");
    for ( j = 0; j < v7; ++j )
      Scaleform::GFx::AS2::Disasm::LogF(this, "%c", InstructionData[j + 3]);
    Scaleform::GFx::AS2::Disasm::LogF(this, "\"\n");
  }
  else
  {
    if ( ArgFormat == 3 )
    {
      Scaleform::GFx::AS2::Disasm::LogF(this, " %d\n", InstructionData[3]);
      return;
    }
    if ( ArgFormat == 4 )
    {
      Scaleform::GFx::AS2::Disasm::LogF(this, " %d\n", *(unsigned __int16 *)(InstructionData + 3));
      return;
    }
    if ( ArgFormat == 5 )
    {
      v10 = *(unsigned __int16 *)(InstructionData + 3);
      if ( (v10 & 0x8000) != 0 )
        v10 |= 0xFFFF8000;
      Scaleform::GFx::AS2::Disasm::LogF(this, " %d\n", v10);
    }
    else if ( ArgFormat == 6 )
    {
      Scaleform::GFx::AS2::Disasm::LogF(this, "\n");
      v11 = 0;
      if ( v7 > 0 )
      {
        do
        {
          v12 = InstructionData[v11++ + 3];
          Scaleform::GFx::AS2::Disasm::LogF(this, "\t\t");
          if ( v12 )
          {
            switch ( v12 )
            {
              case 1:
                v14 = *(float *)&InstructionData[v11 + 3];
                v11 += 4;
                Scaleform::GFx::AS2::Disasm::LogF(this, "(float) %f\n", v14);
                break;
              case 2:
                Scaleform::GFx::AS2::Disasm::LogF(this, "NULL\n");
                break;
              case 3:
                Scaleform::GFx::AS2::Disasm::LogF(this, "undef\n");
                break;
              case 4:
                v28 = InstructionData[v11++ + 3];
                Scaleform::GFx::AS2::Disasm::LogF(this, "reg[%d]\n", v28);
                break;
              case 5:
                v29 = InstructionData[v11++ + 3];
                Scaleform::GFx::AS2::Disasm::LogF(this, "bool(%d)\n", v29);
                break;
              case 6:
                HIDWORD(v36) = *(_DWORD *)&InstructionData[v11 + 3];
                LODWORD(v36) = *(_DWORD *)&InstructionData[v11 + 7];
                v11 += 8;
                Scaleform::GFx::AS2::Disasm::LogF(this, "(double) %f\n", v36);
                break;
              case 7:
                v30 = InstructionData[v11 + 3]
                    | ((InstructionData[v11 + 4] | (*(unsigned __int16 *)&InstructionData[v11 + 5] << 8)) << 8);
                v11 += 4;
                Scaleform::GFx::AS2::Disasm::LogF(this, "(int) %d\n", v30);
                break;
              case 8:
                v31 = InstructionData[v11++ + 3];
                Scaleform::GFx::AS2::Disasm::LogF(this, "DictLookup[%d]\n", v31);
                break;
              case 9:
                v32 = *(unsigned __int16 *)&InstructionData[v11 + 3];
                v11 += 2;
                Scaleform::GFx::AS2::Disasm::LogF(this, "DictLookupLg[%d]\n", v32);
                break;
            }
          }
          else
          {
            Scaleform::GFx::AS2::Disasm::LogF(this, "\"");
            for ( k = InstructionData[v11 + 3]; k; ++v11 )
            {
              Scaleform::GFx::AS2::Disasm::LogF(this, "%c", k);
              k = InstructionData[v11 + 4];
            }
            ++v11;
            Scaleform::GFx::AS2::Disasm::LogF(this, "\"\n");
          }
        }
        while ( v11 < v39 );
      }
    }
    else
    {
      if ( ArgFormat != 7 )
      {
        if ( ArgFormat == 9 )
        {
          v18 = strlen((const char *)InstructionData + 3);
          v19 = *(unsigned __int16 *)&InstructionData[v18 + 4];
          v20 = v18 + 4;
          Scaleform::GFx::AS2::Disasm::LogF(
            this,
            "\n\t\tname = '%s', ArgCount = %d, RegCount = %d\n",
            (const char *)InstructionData + 3,
            v19,
            InstructionData[v18 + 6]);
          v21 = *(unsigned __int16 *)&InstructionData[v20 + 3];
          v27 = *(_WORD *)&InstructionData[v20 + 3] & 1;
          v22 = v20 + 2;
          Scaleform::GFx::AS2::Disasm::LogF(
            this,
            "\t\t        pg = %d\n"
            "\t\t        pp = %d\n"
            "\t\t        pr = %d\n"
            "\t\tss = %d, ps = %d\n"
            "\t\tsa = %d, pa = %d\n"
            "\t\tst = %d, pt = %d\n",
            (v21 >> 8) & 1,
            (v21 >> 7) & 1,
            (v21 >> 6) & 1,
            (v21 >> 5) & 1,
            (v21 >> 4) & 1,
            (v21 >> 3) & 1,
            (v21 >> 2) & 1,
            (v21 >> 1) & 1,
            v27);
          for ( m = 0; m < v19; ++m )
          {
            v23 = InstructionData[v22 + 3];
            v24 = v22 + 1;
            v37 = v23;
            v33 = (const char *)&InstructionData[v24 + 3];
            v22 = v24 + strlen(v33) + 1;
            Scaleform::GFx::AS2::Disasm::LogF(this, "\t\targ[%d] - reg[%d] - '%s'\n", m, v37, v33);
          }
        }
        else
        {
          if ( ArgFormat != 8 )
            return;
          v25 = &InstructionData[strlen((const char *)InstructionData + 3) + 4];
          v26 = *(unsigned __int16 *)v25;
          v22 = v25 - (InstructionData + 4) + 3;
          Scaleform::GFx::AS2::Disasm::LogF(
            this,
            "\n\t\tname = '%s', ArgCount = %d\n",
            (const char *)InstructionData + 3,
            v26);
          for ( n = 0; n < v26; ++n )
          {
            v34 = (const char *)&InstructionData[v22 + 3];
            v22 += strlen(v34) + 1;
            Scaleform::GFx::AS2::Disasm::LogF(this, "\t\targ[%d] - '%s'\n", n, v34);
          }
        }
        Scaleform::GFx::AS2::Disasm::LogF(
          this,
          "\t\tfunction length = %d\n",
          *(unsigned __int16 *)&InstructionData[v22 + 3]);
        return;
      }
      v15 = *(unsigned __int16 *)(InstructionData + 3);
      v16 = 2;
      Scaleform::GFx::AS2::Disasm::LogF(this, " [%d]\n", v15);
      if ( v15 > 0 )
      {
        v35 = v15;
        do
        {
          Scaleform::GFx::AS2::Disasm::LogF(this, "\t\t");
          Scaleform::GFx::AS2::Disasm::LogF(this, "\"");
          v17 = InstructionData[v16 + 3];
          if ( v17 )
          {
            while ( v16 < v39 )
            {
              Scaleform::GFx::AS2::Disasm::LogF(this, "%c", v17);
              v17 = InstructionData[v16++ + 4];
              if ( !v17 )
                goto LABEL_61;
            }
            Scaleform::GFx::AS2::Disasm::LogF(this, "<disasm error -- length exceeded>\n");
          }
LABEL_61:
          Scaleform::GFx::AS2::Disasm::LogF(this, "\"\n");
          ++v16;
          --v35;
        }
        while ( v35 );
      }
    }
  }
}
