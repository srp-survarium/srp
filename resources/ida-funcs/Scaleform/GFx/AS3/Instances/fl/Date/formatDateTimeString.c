unsigned int __cdecl Scaleform::GFx::AS3::Instances::fl::Date::formatDateTimeString(
        char *buffer,
        unsigned int bufferSize,
        double t,
        int tza,
        bool needDate,
        bool needTime,
        bool utc)
{
  long double time; // st7
  unsigned int v9; // esi
  int v10; // eax
  char *v11; // ebx
  int v12; // eax
  char *v13; // ebx
  unsigned int v14; // eax
  char *v15; // ecx
  int tzaDelta; // [esp+48h] [ebp-88h] BYREF
  const char *gmtString; // [esp+4Ch] [ebp-84h] BYREF
  int v3; // [esp+50h] [ebp-80h] BYREF
  int v2; // [esp+54h] [ebp-7Ch] BYREF
  Scaleform::MsgFormat::Sink result; // [esp+58h] [ebp-78h] BYREF
  Scaleform::MsgFormat::Sink v21; // [esp+6Ch] [ebp-64h] BYREF
  Scaleform::GFx::AS3::Instances::fl::Date::DateHolder v22; // [esp+78h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::Instances::fl::Date::TimeHolder th; // [esp+A0h] [ebp-30h] BYREF

  time = t;
  *(double *)&result.Type = t;
  if ( ((int)result.SinkData.pStr & 0x7FF00000) == 0x7FF00000 && (int)result.SinkData.pStr & 0xFFFFF | result.Type )
  {
    strcpy(buffer, "Invalid Date");
    return 12;
  }
  else
  {
    if ( !utc )
    {
      time = t + (double)tza;
      t = time;
    }
    v9 = 0;
    Scaleform::GFx::AS3::Instances::fl::Date::DateHolder::DateHolder(&v22, time, 0.0);
    if ( needDate )
    {
      v10 = (int)fmod(floor(t / 86400000.0) + 4.0, 7.0);
      v11 = buffer;
      gmtString = (const char *)(int)v22.Entries[2];
      result.Type = tDataPtr;
      result.SinkData = (Scaleform::MsgFormat::Sink::SinkDataType)__PAIR64__(bufferSize, (unsigned int)buffer);
      v9 = Scaleform::Format<char const *,char const *,int>(
             &result,
             "{0} {1} {2} ",
             &(&Scaleform::GFx::AS3::Instances::fl::Date::DayNames[v10])[v10 < 0 ? 7 : 0],
             &Scaleform::GFx::AS3::Instances::fl::Date::MonthNames[(int)v22.Entries[1]],
             (int *)&gmtString);
    }
    else
    {
      v11 = buffer;
    }
    if ( needTime )
    {
      Scaleform::GFx::AS3::Instances::fl::Date::TimeHolder::TimeHolder(&th, t, 0.0);
      v12 = tza / 60000 + 40 * (tza / 60000 / 60);
      tzaDelta = v12;
      gmtString = "GMT+";
      v13 = "{0:02}:{1:02}:{2:02}";
      if ( !utc )
      {
        v13 = "{0:02}:{1:02}:{2:02} {3}{4:04}";
        if ( v12 < 0 )
        {
          tzaDelta = -v12;
          gmtString = "GMT-";
        }
      }
      v3 = (int)th.Entries[2];
      v2 = (int)th.Entries[1];
      result.Type = (int)th.Entries[0];
      v21.SinkData.pStr = (Scaleform::String *)&buffer[v9];
      v21.SinkData.DataPtr.Size = bufferSize - v9;
      v21.Type = tDataPtr;
      v14 = Scaleform::Format<int,int,int,char const *,int>(&v21, v13, (int *)&result, &v2, &v3, &gmtString, &tzaDelta);
      v11 = buffer;
      v9 += v14;
    }
    if ( needDate )
    {
      result.Type = (int)v22.Entries[0];
      v15 = " {0}";
      if ( !needTime )
        v15 = "{0}";
      v21.SinkData.pStr = (Scaleform::String *)&v11[v9];
      v21.Type = tDataPtr;
      v21.SinkData.DataPtr.Size = bufferSize - v9;
      v9 += Scaleform::Format<long>(&v21, v15, (int *)&result);
    }
    if ( needTime && utc )
    {
      strcpy(&v11[v9], " UTC");
      v9 += 4;
    }
    return v9;
  }
}
