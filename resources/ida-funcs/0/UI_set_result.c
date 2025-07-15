void __cdecl UI_set_result(ui_st *ui, ui_string_st *uis, char *result)
{
  unsigned __int8 *v3; // edi
  int v4; // ebp
  UI_string_types type; // eax
  char *v6; // eax
  int v7; // eax
  int v8; // eax
  int result_maxsize; // eax
  char *result_buf; // esi
  char v11[16]; // [esp+10h] [ebp-24h] BYREF
  char v12[16]; // [esp+20h] [ebp-14h] BYREF

  v3 = (unsigned __int8 *)result;
  v4 = strlen(result);
  ui->flags &= ~1u;
  if ( uis )
  {
    type = uis->type;
    if ( uis->type > UIT_NONE )
    {
      if ( type <= UIT_VERIFY )
      {
        BIO_snprintf(v12, 0xDu, "%d", uis->_.string_data.result_minsize);
        BIO_snprintf(v11, 0xDu, "%d", uis->_.string_data.result_maxsize);
        if ( v4 >= uis->_.string_data.result_minsize )
        {
          result_maxsize = uis->_.string_data.result_maxsize;
          if ( v4 <= result_maxsize )
          {
            result_buf = uis->result_buf;
            if ( result_buf )
              BUF_strlcpy(result_buf, result, result_maxsize + 1);
            else
              ERR_put_error((int)ui, 0x28u, 105, 105, ".\\crypto\\ui\\ui_lib.c", 886);
          }
          else
          {
            ui->flags |= 1u;
            ERR_put_error((int)ui, 0x28u, 105, 100, ".\\crypto\\ui\\ui_lib.c", 877);
            ERR_add_error_data(5, "You must type in ", v12, " to ", v11, " characters");
          }
        }
        else
        {
          ui->flags |= 1u;
          ERR_put_error((int)ui, 0x28u, 105, 101, ".\\crypto\\ui\\ui_lib.c", 869);
          ERR_add_error_data(5, "You must type in ", v12, " to ", v11, " characters");
        }
      }
      else if ( type == UIT_BOOLEAN )
      {
        v6 = uis->result_buf;
        if ( v6 )
        {
          *v6 = 0;
          if ( *result )
          {
            while ( 1 )
            {
              strchr((char *)uis->_.string_data.result_maxsize, *v3);
              if ( v7 )
              {
                *uis->result_buf = *(_BYTE *)uis->_.string_data.result_maxsize;
                return;
              }
              strchr((char *)uis->_.string_data.test_buf, *v3);
              if ( v8 )
                break;
              if ( !*++v3 )
                return;
            }
            *uis->result_buf = *uis->_.string_data.test_buf;
          }
        }
        else
        {
          ERR_put_error((int)ui, 0x28u, 105, 105, ".\\crypto\\ui\\ui_lib.c", 899);
        }
      }
    }
  }
}
