char __thiscall SpeedTree::CParser::Parse(
        SpeedTree::CParser *this,
        const unsigned __int8 *a2,
        unsigned int a3,
        struct SpeedTree::CCore *a4,
        struct SpeedTree::SGeometry *a5)
{
  int v7; // [esp+4h] [ebp-36A8h]
  SpeedTree::CParser::SLeafCardsTmp::SLod *m; // [esp+8h] [ebp-36A4h]
  int v9; // [esp+Ch] [ebp-36A0h]
  SpeedTree::CParser::STriListTmp::SLod *k; // [esp+10h] [ebp-369Ch]
  int v11; // [esp+14h] [ebp-3698h]
  SpeedTree::CParser::STriListTmp::SLod *j; // [esp+18h] [ebp-3694h]
  int v13; // [esp+1Ch] [ebp-3690h]
  SpeedTree::CParser::STriListTmp::SLod *i; // [esp+20h] [ebp-368Ch]
  _BYTE v15[4]; // [esp+24h] [ebp-3688h] BYREF
  char v16; // [esp+28h] [ebp-3684h] BYREF
  _BYTE v17[4]; // [esp+DECh] [ebp-28C0h] BYREF
  char v18; // [esp+DF0h] [ebp-28BCh] BYREF
  _BYTE v19[4]; // [esp+1BB4h] [ebp-1AF8h] BYREF
  char v20; // [esp+1BB8h] [ebp-1AF4h] BYREF
  _BYTE v21[4]; // [esp+28DCh] [ebp-DD0h] BYREF
  char v22; // [esp+28E0h] [ebp-DCCh] BYREF
  char v23; // [esp+36ABh] [ebp-1h]

  v23 = 0;
  if ( a2 )
  {
    if ( a3 )
    {
      if ( a5 )
      {
        *(_DWORD *)this = a2;
        *((_DWORD *)this + 1) = a3;
        *((_DWORD *)this + 3) = a5;
        *((_DWORD *)this + 2) = 0;
        v13 = 20;
        for ( i = (SpeedTree::CParser::STriListTmp::SLod *)&v22;
              --v13 >= 0;
              i = (SpeedTree::CParser::STriListTmp::SLod *)((char *)i + 176) )
        {
          SpeedTree::CParser::STriListTmp::SLod::SLod(i);
        }
        v11 = 20;
        for ( j = (SpeedTree::CParser::STriListTmp::SLod *)&v16;
              --v11 >= 0;
              j = (SpeedTree::CParser::STriListTmp::SLod *)((char *)j + 176) )
        {
          SpeedTree::CParser::STriListTmp::SLod::SLod(j);
        }
        v9 = 20;
        for ( k = (SpeedTree::CParser::STriListTmp::SLod *)&v18;
              --v9 >= 0;
              k = (SpeedTree::CParser::STriListTmp::SLod *)((char *)k + 176) )
        {
          SpeedTree::CParser::STriListTmp::SLod::SLod(k);
        }
        v7 = 20;
        for ( m = (SpeedTree::CParser::SLeafCardsTmp::SLod *)&v20;
              --v7 >= 0;
              m = (SpeedTree::CParser::SLeafCardsTmp::SLod *)((char *)m + 168) )
        {
          SpeedTree::CParser::SLeafCardsTmp::SLod::SLod(m);
        }
        if ( SpeedTree::CParser::ParseHeader(this)
          && SpeedTree::CParser::ParsePlatform(this)
          && SpeedTree::CParser::ParseExtents(this, a4)
          && SpeedTree::CParser::ParseLOD(this, a4)
          && SpeedTree::CParser::ParseCollisionObjects(this, a4)
          && SpeedTree::CParser::ParseWind(this, a4)
          && SpeedTree::CParser::ParseMaterials(this)
          && SpeedTree::CParser::ParseGeometry(
               this,
               (struct SpeedTree::CParser::STriListTmp *)v21,
               (struct SpeedTree::CParser::STriListTmp *)v15,
               (struct SpeedTree::CParser::STriListTmp *)v17,
               (struct SpeedTree::CParser::SLeafCardsTmp *)v19)
          && SpeedTree::CParser::ParseBillboards(this)
          && SpeedTree::CParser::ParseMasterTable(this)
          && SpeedTree::CParser::ParseCustomData(this, a4) )
        {
          SpeedTree::CParser::SubdivideMasterTable(
            this,
            (const struct SpeedTree::CParser::STriListTmp *)v21,
            (const struct SpeedTree::CParser::STriListTmp *)v15,
            (const struct SpeedTree::CParser::STriListTmp *)v17,
            (const struct SpeedTree::CParser::SLeafCardsTmp *)v19);
          return 1;
        }
      }
      else
      {
        SpeedTree::CCore::SetError("CParser::Parse, pGeometry pointer was NULL");
      }
    }
    else
    {
      SpeedTree::CCore::SetError("CParser::Parse, buffer passed in is too short (%d bytes)", 0);
    }
  }
  else
  {
    SpeedTree::CCore::SetError("CParser::Parse, pMemBlock parameter was NULL");
  }
  return v23;
}
