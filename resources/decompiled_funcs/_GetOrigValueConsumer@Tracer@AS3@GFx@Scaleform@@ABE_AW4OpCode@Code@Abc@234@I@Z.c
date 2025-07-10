Scaleform::GFx::AS3::Abc::Code::OpCode __thiscall Scaleform::GFx::AS3::Tracer::GetOrigValueConsumer(
        Scaleform::GFx::AS3::Tracer *this,
        unsigned int bcp)
{
  unsigned int v3; // ecx
  Scaleform::GFx::AS3::Abc::Code::OpCode result; // eax
  int v5; // ebx
  const unsigned __int8 *pCode; // eax
  int v7; // ebp
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  unsigned __int8 v11; // al
  int v12; // eax
  int v13; // edi
  const unsigned __int8 *v14; // edx
  const unsigned __int8 *v15; // ecx
  int v16; // eax

  v3 = bcp;
  result = op_nop;
  v5 = 1;
  if ( bcp < this->CodeEnd )
  {
    while ( 1 )
    {
      pCode = this->pCode;
      v7 = pCode[v3];
      bcp = v3 + 1;
      if ( v7 == 16 )
      {
        v8 = Scaleform::GFx::AS3::Abc::ReadS24<unsigned char>(pCode, &bcp);
        bcp += v8;
      }
      else
      {
        v9 = v5 - ((*(_BYTE *)&Scaleform::GFx::AS3::Abc::Code::opcode_info[v7] >> 4) & 3);
        if ( (byte_8876B9[2 * v7] & 2) != 0 )
        {
          switch ( this->CF->pFile->File.pObject->Const_Pool.const_multiname.Data.Data[Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(
                                                                                         pCode,
                                                                                         &bcp)].Kind )
          {
            case MN_RTQName:
            case MN_MultinameL:
            case MN_RTQNameA:
            case MN_MultinameLA:
              --v9;
              break;
            case MN_RTQNameL:
            case MN_RTQNameLA:
              v9 -= 2;
              break;
            default:
              break;
          }
        }
        if ( (byte_8876B9[2 * v7] & 1) != 0 )
        {
          v10 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, &bcp);
          if ( v7 == 85 )
            v9 -= 2 * v10;
          else
            v9 -= v10;
        }
        if ( v9 <= 0 )
          return v7;
        v11 = (unsigned __int8)Scaleform::GFx::AS3::Abc::Code::opcode_info[v7];
        v5 = (v11 >> 6) + v9;
        if ( !(byte_8876B9[2 * v7] & 1 | ((byte_8876B9[2 * v7] & 2) != 0)) )
        {
          switch ( v7 )
          {
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
            case 21:
            case 22:
            case 23:
            case 24:
            case 25:
            case 26:
              Scaleform::GFx::AS3::Abc::ReadS24<unsigned char>(this->pCode, &bcp);
              break;
            case 27:
              Scaleform::GFx::AS3::Abc::ReadS24<unsigned char>(this->pCode, &bcp);
              v12 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, &bcp);
              if ( v12 >= 0 )
              {
                v13 = v12 + 1;
                do
                {
                  Scaleform::GFx::AS3::Abc::ReadS24<unsigned char>(this->pCode, &bcp);
                  --v13;
                }
                while ( v13 );
              }
              break;
            case 36:
              ++bcp;
              break;
            case 239:
              v14 = this->pCode;
              ++bcp;
              Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v14, &bcp);
              v15 = this->pCode;
              ++bcp;
              Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v15, &bcp);
              break;
            default:
              v16 = ((char)(32 * v11) >> 5) - 1;
              if ( !v16 )
                goto LABEL_25;
              if ( v16 == 1 )
              {
                Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, &bcp);
LABEL_25:
                Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, &bcp);
              }
              break;
          }
        }
      }
      v3 = bcp;
      if ( bcp >= this->CodeEnd )
        return v7;
    }
  }
  return result;
}
