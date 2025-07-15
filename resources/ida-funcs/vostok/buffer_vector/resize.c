void __usercall vostok::buffer_vector<unsigned short>::resize(
        vostok::buffer_vector<unsigned short> *this@<ecx>,
        int *a2@<esi>)
{
  int v2; // eax
  unsigned int v3; // edi
  unsigned int v4; // eax
  int v5; // ebx
  int v6; // ecx
  int v7; // eax
  _WORD *i; // edx
  const char *v9; // [esp+0h] [ebp-10h]
  _WORD *v10; // [esp+8h] [ebp-8h]
  bool v11; // [esp+Fh] [ebp-1h] BYREF

  v2 = *a2;
  v3 = (a2[1] - *a2) >> 1;
  if ( this != (vostok::buffer_vector<unsigned short> *)v3 )
  {
    if ( (unsigned int)this >= v3 )
    {
      v5 = 2 * (_DWORD)this;
      if ( 2 * (int)this + v2 > (unsigned int)a2[2]
        && !`vostok::buffer_vector<unsigned short>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        v11 = 0;
        vostok::debug::on_error(
          &v11,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<unsigned short>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v9);
        if ( vostok::debug::is_debugger_present() || v11 )
          __debugbreak();
      }
      v6 = v5 + *a2;
      v7 = *a2 + 2 * v3;
      if ( v7 != v6 )
      {
        v10 = (_WORD *)(v7 + 2);
        do
        {
          for ( i = (_WORD *)v7; i != v10; ++i )
          {
            if ( i )
              *i = 0;
          }
          ++v10;
          v7 += 2;
        }
        while ( v7 != v6 );
      }
      a2[1] = v5 + *a2;
    }
    else
    {
      v4 = v2 + 2 * (_DWORD)this;
      a2[1] = v4;
      if ( v4 > a2[2] && !`vostok::buffer_vector<unsigned short>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        v11 = 0;
        vostok::debug::on_error(
          &v11,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<unsigned short>::resize",
          (const char *)0x98,
          "buffer overflow",
          v9);
        if ( vostok::debug::is_debugger_present() || v11 )
          __debugbreak();
      }
    }
  }
}


void __userpurge vostok::buffer_vector<float>::resize(
        vostok::buffer_vector<float> *this@<ecx>,
        int *a2@<esi>,
        float *size,
        const float *value)
{
  int v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // eax
  int v7; // ebx
  float *v8; // ecx
  float *i; // eax
  const char *v10; // [esp+0h] [ebp-Ch]
  bool v11; // [esp+Bh] [ebp-1h] BYREF

  v4 = *a2;
  v5 = (a2[1] - *a2) >> 2;
  if ( this != (vostok::buffer_vector<float> *)v5 )
  {
    if ( (unsigned int)this >= v5 )
    {
      v7 = 4 * (_DWORD)this;
      if ( 4 * (int)this + v4 > (unsigned int)a2[2]
        && !`vostok::buffer_vector<float>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        v11 = 0;
        vostok::debug::on_error(
          &v11,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<float>::resize",
          (const char *)0xB7,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || v11 )
          __debugbreak();
      }
      v8 = (float *)(v7 + *a2);
      for ( i = (float *)(*a2 + 4 * v5); i != v8; ++i )
      {
        if ( i )
          *i = *size;
      }
      a2[1] = v7 + *a2;
    }
    else
    {
      v6 = v4 + 4 * (_DWORD)this;
      a2[1] = v6;
      if ( v6 > a2[2] && !`vostok::buffer_vector<float>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<float>::resize",
          (const char *)0xB0,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
    }
  }
}


void __usercall vostok::buffer_vector<ID3D11SamplerState *>::resize(
        vostok::buffer_vector<ID3D11SamplerState *> *this@<ecx>,
        int *a2@<esi>)
{
  int v2; // eax
  unsigned int v3; // edi
  unsigned int v4; // eax
  int v5; // ebx
  int v6; // edx
  int v7; // eax
  _DWORD *v8; // edi
  _DWORD *i; // ecx
  const char *v10; // [esp+0h] [ebp-10h]
  bool v11; // [esp+Fh] [ebp-1h] BYREF

  v2 = *a2;
  v3 = (a2[1] - *a2) >> 2;
  if ( this != (vostok::buffer_vector<ID3D11SamplerState *> *)v3 )
  {
    if ( (unsigned int)this >= v3 )
    {
      v5 = 4 * (_DWORD)this;
      if ( 4 * (int)this + v2 > (unsigned int)a2[2]
        && !`vostok::buffer_vector<ID3D11SamplerState *>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        v11 = 0;
        vostok::debug::on_error(
          &v11,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct ID3D11SamplerState *>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || v11 )
          __debugbreak();
      }
      v6 = v5 + *a2;
      v7 = *a2 + 4 * v3;
      if ( v7 != v6 )
      {
        v8 = (_DWORD *)(v7 + 4);
        do
        {
          for ( i = (_DWORD *)v7; i != v8; ++i )
          {
            if ( i )
              *i = 0;
          }
          v7 += 4;
          ++v8;
        }
        while ( v7 != v6 );
      }
      a2[1] = v5 + *a2;
    }
    else
    {
      v4 = v2 + 4 * (_DWORD)this;
      a2[1] = v4;
      if ( v4 > a2[2] && !`vostok::buffer_vector<ID3D11SamplerState *>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        v11 = 0;
        vostok::debug::on_error(
          &v11,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct ID3D11SamplerState *>::resize",
          (const char *)0x98,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || v11 )
          __debugbreak();
      }
    }
  }
}


void __usercall vostok::buffer_vector<vostok::render::render_surface_instance *>::resize(
        vostok::buffer_vector<vostok::render::render_surface_instance *> *this@<ecx>,
        int *a2@<esi>)
{
  int v2; // ecx
  unsigned int v3; // edi
  unsigned int v4; // eax
  unsigned int v5; // ebx
  unsigned int v6; // edx
  int v7; // eax
  _DWORD *v8; // edi
  _DWORD *i; // ecx
  const char *v10; // [esp+0h] [ebp-10h]
  bool v11; // [esp+Fh] [ebp-1h] BYREF

  v2 = *a2;
  v3 = (a2[1] - *a2) >> 2;
  if ( s_visible_surfaces_limit_value != v3 )
  {
    if ( s_visible_surfaces_limit_value >= v3 )
    {
      v5 = 4 * s_visible_surfaces_limit_value;
      if ( 4 * s_visible_surfaces_limit_value + v2 > a2[2]
        && !BYTE1(vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst.elements[2]) )
      {
        v11 = 0;
        vostok::debug::on_error(
          &v11,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct vostok::render::render_surface_instance *>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || v11 )
          __debugbreak();
      }
      v6 = v5 + *a2;
      v7 = *a2 + 4 * v3;
      if ( v7 != v6 )
      {
        v8 = (_DWORD *)(v7 + 4);
        do
        {
          for ( i = (_DWORD *)v7; i != v8; ++i )
          {
            if ( i )
              *i = 0;
          }
          v7 += 4;
          ++v8;
        }
        while ( v7 != v6 );
      }
      a2[1] = v5 + *a2;
    }
    else
    {
      v4 = v2 + 4 * s_visible_surfaces_limit_value;
      a2[1] = v4;
      if ( v4 > a2[2] && !LOBYTE(vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst.elements[2]) )
      {
        v11 = 0;
        vostok::debug::on_error(
          &v11,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct vostok::render::render_surface_instance *>::resize",
          (const char *)0x98,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || v11 )
          __debugbreak();
      }
    }
  }
}


void __usercall vostok::buffer_vector<vostok::physics::old_bullet_character_controller::sweep_test_cache_item *>::resize(
        vostok::buffer_vector<vostok::physics::old_bullet_character_controller::sweep_test_cache_item *> *this@<ecx>,
        int *a2@<edi>)
{
  int v2; // eax
  unsigned int v3; // esi
  unsigned int v4; // eax
  int v5; // ebx
  int v6; // eax
  _DWORD *v7; // edx
  _DWORD *i; // ecx
  const char *v9; // [esp+0h] [ebp-10h]
  bool v10; // [esp+Fh] [ebp-1h] BYREF

  v2 = *a2;
  v3 = (a2[1] - *a2) >> 2;
  if ( v3 != 32 )
  {
    if ( v3 <= 0x20 )
    {
      if ( v2 + 128 > (unsigned int)a2[2]
        && !`vostok::buffer_vector<vostok::physics::old_bullet_character_controller::sweep_test_cache_item *>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        v10 = 0;
        vostok::debug::on_error(
          &v10,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct vostok::physics::old_bullet_character_controller::sweep_test_cache_item *>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v9);
        if ( vostok::debug::is_debugger_present() || v10 )
          __debugbreak();
      }
      v5 = *a2 + 128;
      v6 = *a2 + 4 * v3;
      if ( v6 != v5 )
      {
        v7 = (_DWORD *)(v6 + 4);
        do
        {
          for ( i = (_DWORD *)v6; i != v7; ++i )
          {
            if ( i )
              *i = 0;
          }
          v6 += 4;
          ++v7;
        }
        while ( v6 != v5 );
      }
      a2[1] = *a2 + 128;
    }
    else
    {
      v4 = v2 + 128;
      a2[1] = v4;
      if ( v4 > a2[2]
        && !`vostok::buffer_vector<vostok::physics::old_bullet_character_controller::sweep_test_cache_item *>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        v10 = 0;
        vostok::debug::on_error(
          &v10,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct vostok::physics::old_bullet_character_controller::sweep_test_cache_item *>::resize",
          (const char *)0x98,
          "buffer overflow",
          v9);
        if ( vostok::debug::is_debugger_present() || v10 )
          __debugbreak();
      }
    }
  }
}


void __userpurge vostok::buffer_vector<survarium::single_game_effect *>::resize(
        vostok::buffer_vector<survarium::single_game_effect *> *this@<ecx>,
        int *a2@<esi>,
        _DWORD *size,
        survarium::single_game_effect *const *value)
{
  int v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // eax
  int v7; // ebx
  _DWORD *v8; // ecx
  _DWORD *i; // eax
  const char *v10; // [esp+0h] [ebp-Ch]
  bool v11; // [esp+Bh] [ebp-1h] BYREF

  v4 = *a2;
  v5 = (a2[1] - *a2) >> 2;
  if ( this != (vostok::buffer_vector<survarium::single_game_effect *> *)v5 )
  {
    if ( (unsigned int)this >= v5 )
    {
      v7 = 4 * (_DWORD)this;
      if ( 4 * (int)this + v4 > (unsigned int)a2[2]
        && !`vostok::buffer_vector<survarium::single_game_effect *>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        v11 = 0;
        vostok::debug::on_error(
          &v11,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class survarium::single_game_effect *>::resize",
          (const char *)0xB7,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || v11 )
          __debugbreak();
      }
      v8 = (_DWORD *)(v7 + *a2);
      for ( i = (_DWORD *)(*a2 + 4 * v5); i != v8; ++i )
      {
        if ( i )
          *i = *size;
      }
      a2[1] = v7 + *a2;
    }
    else
    {
      v6 = v4 + 4 * (_DWORD)this;
      a2[1] = v6;
      if ( v6 > a2[2]
        && !`vostok::buffer_vector<survarium::single_game_effect *>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class survarium::single_game_effect *>::resize",
          (const char *)0xB0,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
    }
  }
}


void __usercall vostok::buffer_vector<vostok::render::stage *>::resize(
        vostok::buffer_vector<vostok::render::stage *> *this@<ecx>,
        int *a2@<edi>)
{
  int v2; // eax
  unsigned int v3; // esi
  unsigned int v4; // eax
  int v5; // ebx
  int v6; // eax
  _DWORD *v7; // edx
  _DWORD *i; // ecx
  const char *v9; // [esp+0h] [ebp-10h]
  bool v10; // [esp+Fh] [ebp-1h] BYREF

  v2 = *a2;
  v3 = (a2[1] - *a2) >> 2;
  if ( v3 != 28 )
  {
    if ( v3 <= 0x1C )
    {
      if ( v2 + 112 > (unsigned int)a2[2]
        && !`vostok::buffer_vector<vostok::render::stage *>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        v10 = 0;
        vostok::debug::on_error(
          &v10,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::render::stage *>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v9);
        if ( vostok::debug::is_debugger_present() || v10 )
          __debugbreak();
      }
      v5 = *a2 + 112;
      v6 = *a2 + 4 * v3;
      if ( v6 != v5 )
      {
        v7 = (_DWORD *)(v6 + 4);
        do
        {
          for ( i = (_DWORD *)v6; i != v7; ++i )
          {
            if ( i )
              *i = 0;
          }
          v6 += 4;
          ++v7;
        }
        while ( v6 != v5 );
      }
      a2[1] = *a2 + 112;
    }
    else
    {
      v4 = v2 + 112;
      a2[1] = v4;
      if ( v4 > a2[2]
        && !`vostok::buffer_vector<vostok::render::stage *>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        v10 = 0;
        vostok::debug::on_error(
          &v10,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::render::stage *>::resize",
          (const char *)0x98,
          "buffer overflow",
          v9);
        if ( vostok::debug::is_debugger_present() || v10 )
          __debugbreak();
      }
    }
  }
}


void __userpurge vostok::buffer_vector<vostok::variant<32> const *>::resize(
        vostok::buffer_vector<vostok::variant<32> const *> *this@<ecx>,
        int *a2@<esi>,
        _DWORD *size,
        const vostok::variant<32> *const *value)
{
  int v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // eax
  int v7; // ebx
  _DWORD *v8; // ecx
  _DWORD *i; // eax
  const char *v10; // [esp+0h] [ebp-Ch]
  bool v11; // [esp+Bh] [ebp-1h] BYREF

  v4 = *a2;
  v5 = (a2[1] - *a2) >> 2;
  if ( this != (vostok::buffer_vector<vostok::variant<32> const *> *)v5 )
  {
    if ( (unsigned int)this >= v5 )
    {
      v7 = 4 * (_DWORD)this;
      if ( 4 * (int)this + v4 > (unsigned int)a2[2]
        && !`vostok::buffer_vector<vostok::variant<32> const *>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        v11 = 0;
        vostok::debug::on_error(
          &v11,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::variant<32> const *>::resize",
          (const char *)0xB7,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || v11 )
          __debugbreak();
      }
      v8 = (_DWORD *)(v7 + *a2);
      for ( i = (_DWORD *)(*a2 + 4 * v5); i != v8; ++i )
      {
        if ( i )
          *i = *size;
      }
      a2[1] = v7 + *a2;
    }
    else
    {
      v6 = v4 + 4 * (_DWORD)this;
      a2[1] = v6;
      if ( v6 > a2[2]
        && !`vostok::buffer_vector<vostok::variant<32> const *>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::variant<32> const *>::resize",
          (const char *)0xB0,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
    }
  }
}


void __usercall vostok::buffer_vector<vostok::render::batched_vertex_source>::resize(
        vostok::buffer_vector<vostok::render::batched_vertex_source> *this@<ecx>,
        int *a2@<esi>)
{
  int v2; // ebx
  unsigned int v3; // edi
  unsigned int v4; // eax
  int v5; // ecx
  int v6; // edi
  float v7; // xmm0_4
  float *v8; // edx
  float *v9; // eax
  const char *v10; // [esp+0h] [ebp-10h]
  int v11; // [esp+8h] [ebp-8h]
  int v12; // [esp+8h] [ebp-8h]
  bool v13; // [esp+Fh] [ebp-1h] BYREF

  v2 = *a2;
  v3 = (a2[1] - *a2) / 36;
  if ( this != (vostok::buffer_vector<vostok::render::batched_vertex_source> *)v3 )
  {
    if ( (unsigned int)this >= v3 )
    {
      v5 = 36 * (_DWORD)this;
      v11 = v5;
      if ( v5 + v2 > (unsigned int)a2[2]
        && !`vostok::buffer_vector<vostok::render::batched_vertex_source>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        v13 = 0;
        vostok::debug::on_error(
          &v13,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct vostok::render::batched_vertex_source>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || v13 )
          __debugbreak();
        v5 = v11;
      }
      v6 = *a2 + 36 * v3;
      v12 = v5 + *a2;
      if ( v6 != v12 )
      {
        v7 = SNaN;
        v8 = (float *)(v6 + 36);
        do
        {
          if ( (float *)v6 != v8 )
          {
            v9 = v8 - 6;
            do
            {
              if ( v9 != (float *)12 )
              {
                *v9 = NAN;
                v9[1] = NAN;
                v9[2] = NAN;
                v9[3] = NAN;
                v9[4] = v7;
                v9[5] = v7;
              }
              v9 += 9;
            }
            while ( v9 - 3 != v8 );
          }
          v6 += 36;
          v8 += 9;
        }
        while ( v6 != v12 );
      }
      a2[1] = v5 + *a2;
    }
    else
    {
      v4 = 36 * (_DWORD)this + v2;
      a2[1] = v4;
      if ( v4 > a2[2]
        && !`vostok::buffer_vector<vostok::render::batched_vertex_source>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        v13 = 0;
        vostok::debug::on_error(
          &v13,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct vostok::render::batched_vertex_source>::resize",
          (const char *)0x98,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || v13 )
          __debugbreak();
      }
    }
  }
}


void __thiscall vostok::buffer_vector<vostok::apc::callback>::resize(
        vostok::buffer_vector<vostok::apc::callback> *this)
{
  vostok::apc::callback *m_begin; // ecx
  unsigned int v2; // esi
  vostok::apc::callback *v3; // edi
  int *v4; // esi
  const char *v5; // [esp+0h] [ebp-18h]
  vostok::apc::callback *end; // [esp+10h] [ebp-8h] BYREF
  bool do_debug_break; // [esp+17h] [ebp-1h] BYREF

  m_begin = g_threads.m_begin;
  v2 = g_threads.m_end - g_threads.m_begin;
  if ( v2 != 11 )
  {
    if ( v2 <= 0xB )
    {
      if ( &g_threads.m_begin[11] > g_threads.m_max_end
        && !HIBYTE(vostok::testing::suite_base<vostok::engine_test_suite>::s_suite_creation_flag.m_mutex[0]) )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct vostok::apc::callback>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v5);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
        m_begin = g_threads.m_begin;
      }
      end = m_begin + 11;
      vostok::buffer_vector<vostok::apc::callback>::construct(&m_begin[v2], &end);
      g_threads.m_end = g_threads.m_begin + 11;
    }
    else
    {
      v3 = &g_threads.m_begin[v2];
      v4 = (int *)&g_threads.m_begin[11];
      if ( g_threads.m_begin + 11 != v3 )
      {
        do
        {
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_begin,
            v4);
          v4 += 12;
        }
        while ( v4 != (int *)v3 );
        m_begin = g_threads.m_begin;
      }
      g_threads.m_end = m_begin + 11;
      if ( &m_begin[11] > g_threads.m_max_end
        && !BYTE6(vostok::testing::suite_base<vostok::engine_test_suite>::s_suite_creation_flag.m_mutex[0]) )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct vostok::apc::callback>::resize",
          (const char *)0x98,
          "buffer overflow",
          v5);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
  }
}


void __userpurge vostok::buffer_vector<survarium::damage_protector>::resize(
        unsigned int size@<eax>,
        survarium::damage_protector *this)
{
  vostok::buffer_vector<survarium::damage_protector> *v2; // ebx
  survarium::damage_protector *v3; // ecx
  unsigned int v4; // esi
  unsigned int v5; // edi
  vostok::buffer_vector<survarium::damage_protector> *i; // esi
  survarium::damage_protector *v7; // eax
  unsigned int v8; // edi
  vostok::buffer_vector<survarium::damage_protector> *v9; // esi
  vostok::buffer_vector<survarium::damage_protector> *v10; // ecx
  vostok::buffer_vector<survarium::damage_protector> *v11; // eax
  const char *v12; // [esp+0h] [ebp-Ch]

  v2 = (vostok::buffer_vector<survarium::damage_protector> *)this;
  v3 = (survarium::damage_protector *)this->__vftable;
  v4 = ((char *)(&this->__vftable)[1] - (char *)this->__vftable) / 112;
  if ( size != v4 )
  {
    if ( size >= v4 )
    {
      v8 = size;
      if ( (boost::detail::function::vtable_base *)&v3[size] > this->reduce_incoming_damage_functor.vtable
        && !`vostok::buffer_vector<survarium::damage_protector>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        HIBYTE(this) = 0;
        vostok::debug::on_error(
          (bool *)&this + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct survarium::damage_protector>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v12);
        if ( vostok::debug::is_debugger_present() || HIBYTE(this) )
          __debugbreak();
      }
      v9 = (vostok::buffer_vector<survarium::damage_protector> *)&v2->m_begin[v4];
      this = &v2->m_begin[v8];
      if ( v9 != (vostok::buffer_vector<survarium::damage_protector> *)this )
      {
        v10 = (vostok::buffer_vector<survarium::damage_protector> *)((char *)v9 + 112);
        do
        {
          if ( v9 != v10 )
          {
            v11 = v10 - 6;
            do
            {
              if ( v11 != (vostok::buffer_vector<survarium::damage_protector> *)40 )
              {
                v11[-4].m_max_end = (survarium::damage_protector *)&survarium::damage_protector::`vftable';
                v11[-3].m_end = 0;
                v11->m_begin = 0;
                v11[2].m_max_end = 0;
                v11[5].m_end = 0;
              }
              v11 = (vostok::buffer_vector<survarium::damage_protector> *)((char *)v11 + 112);
            }
            while ( &v11[-4].m_max_end != (survarium::damage_protector **)v10 );
          }
          v9 = (vostok::buffer_vector<survarium::damage_protector> *)((char *)v9 + 112);
          v10 = (vostok::buffer_vector<survarium::damage_protector> *)((char *)v10 + 112);
        }
        while ( v9 != (vostok::buffer_vector<survarium::damage_protector> *)this );
      }
      v2->m_end = &v2->m_begin[v8];
    }
    else
    {
      v5 = size;
      this = &v3[v4];
      for ( i = (vostok::buffer_vector<survarium::damage_protector> *)&v3[size];
            i != (vostok::buffer_vector<survarium::damage_protector> *)this;
            i = (vostok::buffer_vector<survarium::damage_protector> *)((char *)i + 112) )
      {
        ((void (__thiscall *)(vostok::buffer_vector<survarium::damage_protector> *, _DWORD))i->m_begin->__vftable)(i, 0);
      }
      v7 = &v2->m_begin[v5];
      v2->m_end = v7;
      if ( v7 > v2->m_max_end
        && !`vostok::buffer_vector<survarium::damage_protector>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        HIBYTE(this) = 0;
        vostok::debug::on_error(
          (bool *)&this + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct survarium::damage_protector>::resize",
          (const char *)0x98,
          "buffer overflow",
          v12);
        if ( vostok::debug::is_debugger_present() || HIBYTE(this) )
          __debugbreak();
      }
    }
  }
}


void __userpurge vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data>::resize(
        vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data> *this@<ecx>,
        int *a2@<edi>,
        unsigned int size)
{
  int v3; // ecx
  unsigned int v4; // ebx
  unsigned int v5; // esi
  int v6; // esi
  survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *j; // ebx
  unsigned int v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // ecx
  int v11; // esi
  _DWORD *v12; // edx
  _DWORD *i; // eax
  const char *v14; // [esp+0h] [ebp-Ch]

  v3 = *a2;
  v4 = size;
  v5 = (a2[1] - *a2) / 12;
  if ( size != v5 )
  {
    if ( size >= v5 )
    {
      v9 = 12 * size;
      if ( 12 * size + v3 > a2[2]
        && !`vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct survarium::hud_game_effect_presenter::effect_data>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v14);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
      v10 = v9 + *a2;
      v11 = *a2 + 12 * v5;
      if ( v11 != v10 )
      {
        v12 = (_DWORD *)(v11 + 12);
        do
        {
          for ( i = (_DWORD *)v11; i != v12; i += 3 )
          {
            if ( i )
            {
              *i = 0;
              i[1] = 5;
              i[2] = 0;
            }
          }
          v11 += 12;
          v12 += 3;
        }
        while ( v11 != v10 );
      }
      a2[1] = v9 + *a2;
    }
    else
    {
      size = v3 + 12 * v5;
      v6 = 12 * v4;
      for ( j = (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)(12 * v4 + v3);
            j != (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)size;
            j += 3 )
      {
        survarium::loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>::~loose_ptr<survarium::particle_game_effect const,survarium::loose_ptr_data,vostok::threading::single_threading_policy>(j);
      }
      v8 = v6 + *a2;
      a2[1] = v8;
      if ( v8 > a2[2]
        && !`vostok::buffer_vector<survarium::hud_game_effect_presenter::effect_data>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct survarium::hud_game_effect_presenter::effect_data>::resize",
          (const char *)0x98,
          "buffer overflow",
          v14);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
    }
  }
}


void __userpurge vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::resize(
        unsigned int size@<eax>,
        survarium::particle_game_effect_presenter::effect_data *this)
{
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data> *v2; // ebx
  survarium::particle_game_effect_presenter::effect_data *m_object; // eax
  unsigned int v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // edi
  survarium::particle_game_effect_presenter::effect_data *m_begin; // eax
  const char *v9; // [esp+0h] [ebp-Ch]

  v2 = (vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data> *)this;
  m_object = (survarium::particle_game_effect_presenter::effect_data *)this->effect.m_object;
  v5 = ((char *)this->particle_system.m_object - (char *)this->effect.m_object) >> 4;
  if ( size != v5 )
  {
    if ( size >= v5 )
    {
      v7 = size;
      if ( (unsigned int)&m_object[v7] > LODWORD(this->time_to_finish)
        && !`vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        HIBYTE(this) = 0;
        vostok::debug::on_error(
          (bool *)&this + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct survarium::particle_game_effect_presenter::effect_data>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v9);
        if ( vostok::debug::is_debugger_present() || HIBYTE(this) )
          __debugbreak();
      }
      m_begin = v2->m_begin;
      this = &v2->m_begin[v7];
      vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::construct(&m_begin[v5], &this);
      v2->m_end = &v2->m_begin[v7];
    }
    else
    {
      this = &m_object[v5];
      vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::destroy(&m_object[size], &this);
      v6 = (unsigned int)&v2->m_begin[size];
      v2->m_end = (survarium::particle_game_effect_presenter::effect_data *)v6;
      if ( (survarium::particle_game_effect_presenter::effect_data *)v6 > v2->m_max_end
        && !`vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        HIBYTE(this) = 0;
        vostok::debug::on_error(
          (bool *)&this + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct survarium::particle_game_effect_presenter::effect_data>::resize",
          (const char *)0x98,
          "buffer overflow",
          v9);
        if ( vostok::debug::is_debugger_present() || HIBYTE(this) )
          __debugbreak();
      }
    }
  }
}


void __userpurge vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data>::resize(
        unsigned int size@<eax>,
        vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data> *this)
{
  vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data> *v2; // ebx
  survarium::sound_game_effect_presenter::effect_data *m_begin; // ecx
  unsigned int v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // edi
  survarium::sound_game_effect_presenter::effect_data *v8; // ecx
  int v9; // esi
  _DWORD *v10; // edx
  _DWORD *i; // eax
  const char *v12; // [esp+0h] [ebp-Ch]

  v2 = this;
  m_begin = this->m_begin;
  v5 = this->m_end - this->m_begin;
  if ( size != v5 )
  {
    if ( size >= v5 )
    {
      v7 = size;
      if ( &m_begin[size] > this->m_max_end
        && !`vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        HIBYTE(this) = 0;
        vostok::debug::on_error(
          (bool *)&this + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct survarium::sound_game_effect_presenter::effect_data>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v12);
        if ( vostok::debug::is_debugger_present() || HIBYTE(this) )
          __debugbreak();
      }
      v8 = &v2->m_begin[v7];
      v9 = (int)&v2->m_begin[v5];
      if ( (survarium::sound_game_effect_presenter::effect_data *)v9 != v8 )
      {
        v10 = (_DWORD *)(v9 + 12);
        do
        {
          for ( i = (_DWORD *)v9; i != v10; i += 3 )
          {
            if ( i )
            {
              *i = 0;
              i[1] = 0;
              i[2] = 0;
            }
          }
          v9 += 12;
          v10 += 3;
        }
        while ( (survarium::sound_game_effect_presenter::effect_data *)v9 != v8 );
      }
      v2->m_end = &v2->m_begin[v7];
    }
    else
    {
      this = (vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data> *)&m_begin[v5];
      vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data>::destroy(
        (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> *)&m_begin[size],
        (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **)&this);
      v6 = (unsigned int)&v2->m_begin[size];
      v2->m_end = (survarium::sound_game_effect_presenter::effect_data *)v6;
      if ( (survarium::sound_game_effect_presenter::effect_data *)v6 > v2->m_max_end
        && !`vostok::buffer_vector<survarium::sound_game_effect_presenter::effect_data>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        HIBYTE(this) = 0;
        vostok::debug::on_error(
          (bool *)&this + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct survarium::sound_game_effect_presenter::effect_data>::resize",
          (const char *)0x98,
          "buffer overflow",
          v12);
        if ( vostok::debug::is_debugger_present() || HIBYTE(this) )
          __debugbreak();
      }
    }
  }
}


void __userpurge vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc>::resize(
        vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc> *this@<ecx>,
        int *a2@<esi>,
        vostok::render::grass_layer_desc::model_desc *size)
{
  int v3; // ecx
  unsigned int v4; // edi
  unsigned int v5; // eax
  int v6; // ebx
  vostok::render::grass_layer_desc::model_desc *v7; // edx
  const char *v8; // [esp+0h] [ebp-8h]

  v3 = *a2;
  v4 = (a2[1] - *a2) / 280;
  if ( size != (vostok::render::grass_layer_desc::model_desc *)v4 )
  {
    if ( (unsigned int)size >= v4 )
    {
      v6 = 280 * (_DWORD)size;
      if ( 280 * (int)size + v3 > (unsigned int)a2[2]
        && !`vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct vostok::render::grass_layer_desc::model_desc>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v8);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
      v7 = (vostok::render::grass_layer_desc::model_desc *)(*a2 + 280 * v4);
      size = (vostok::render::grass_layer_desc::model_desc *)(v6 + *a2);
      vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc>::construct(v7, &size);
      a2[1] = v6 + *a2;
    }
    else
    {
      v5 = 280 * (_DWORD)size + v3;
      a2[1] = v5;
      if ( v5 > a2[2]
        && !`vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct vostok::render::grass_layer_desc::model_desc>::resize",
          (const char *)0x98,
          "buffer overflow",
          v8);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
    }
  }
}


void __usercall vostok::buffer_vector<vostok::resources::request>::resize(
        vostok::buffer_vector<vostok::resources::request> *this@<ecx>,
        const char *a2@<ebx>,
        int *a3@<esi>)
{
  int v3; // eax
  unsigned int v4; // edi
  unsigned int v5; // eax
  int v6; // ebx
  vostok::render::stage_screen_space_reflections *v7; // ecx
  int v8; // eax
  int v9; // edi
  vostok::render::stage_screen_space_reflections *v10; // [esp-8h] [ebp-14h]
  const char *v12; // [esp+0h] [ebp-Ch]
  vostok::render::stage_screen_space_reflections *v13; // [esp+4h] [ebp-8h]
  bool v14; // [esp+Bh] [ebp-1h] BYREF

  v3 = *a3;
  v4 = (a3[1] - *a3) >> 3;
  if ( this != (vostok::buffer_vector<vostok::resources::request> *)v4 )
  {
    if ( (unsigned int)this >= v4 )
    {
      v6 = 8 * (_DWORD)this;
      if ( 8 * (int)this + v3 > (unsigned int)a3[2]
        && !`vostok::buffer_vector<vostok::resources::request>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        v14 = 0;
        vostok::debug::on_error(
          &v14,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct vostok::resources::request>::resize",
          (const char *)0x9F,
          "buffer overflow",
          a2);
        if ( vostok::debug::is_debugger_present() || v14 )
          __debugbreak();
      }
      v7 = (vostok::render::stage_screen_space_reflections *)(v6 + *a3);
      v8 = *a3 + 8 * v4;
      v13 = v7;
      if ( (vostok::render::stage_screen_space_reflections *)v8 != v7 )
      {
        do
        {
          v9 = v8 + 8;
          v10 = (vostok::render::stage_screen_space_reflections *)(v8 + 8);
          vostok::memory::process_allocator::finalize_impl(v7);
          v8 = v9;
          v7 = v10;
        }
        while ( (vostok::render::stage_screen_space_reflections *)v9 != v13 );
      }
      a3[1] = v6 + *a3;
    }
    else
    {
      v5 = v3 + 8 * (_DWORD)this;
      a3[1] = v5;
      if ( v5 > a3[2]
        && !`vostok::buffer_vector<vostok::resources::request>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        v14 = 0;
        vostok::debug::on_error(
          &v14,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct vostok::resources::request>::resize",
          (const char *)0x98,
          "buffer overflow",
          v12);
        if ( vostok::debug::is_debugger_present() || v14 )
          __debugbreak();
      }
    }
  }
}


void __usercall vostok::buffer_vector<survarium::squad_member_item>::resize(
        vostok::buffer_vector<survarium::squad_member_item> *this@<esi>,
        unsigned int size@<eax>)
{
  survarium::squad_member_item *m_begin; // ecx
  unsigned int v3; // ebx
  survarium::squad_member_item *v4; // eax
  unsigned int v5; // edi
  vostok::render::stage_screen_space_reflections *v6; // ecx
  survarium::squad_member_item *v7; // eax
  survarium::squad_member_item *v8; // ebx
  vostok::render::stage_screen_space_reflections *v9; // [esp-4h] [ebp-14h]
  const char *v10; // [esp+0h] [ebp-10h]
  vostok::render::stage_screen_space_reflections *v11; // [esp+8h] [ebp-8h]
  bool v12; // [esp+Fh] [ebp-1h] BYREF

  m_begin = this->m_begin;
  v3 = this->m_end - this->m_begin;
  if ( size != v3 )
  {
    if ( size >= v3 )
    {
      v5 = size;
      if ( &m_begin[size] > this->m_max_end
        && !`vostok::buffer_vector<survarium::squad_member_item>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        v12 = 0;
        vostok::debug::on_error(
          &v12,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct survarium::squad_member_item>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || v12 )
          __debugbreak();
      }
      v6 = (vostok::render::stage_screen_space_reflections *)&this->m_begin[v5];
      v7 = &this->m_begin[v3];
      v11 = v6;
      if ( v7 != (survarium::squad_member_item *)v6 )
      {
        do
        {
          v8 = v7 + 1;
          v9 = (vostok::render::stage_screen_space_reflections *)&v7[1];
          vostok::memory::process_allocator::finalize_impl(v6);
          v7 = v8;
          v6 = v9;
        }
        while ( v8 != (survarium::squad_member_item *)v11 );
      }
      this->m_end = &this->m_begin[v5];
    }
    else
    {
      v4 = &m_begin[size];
      this->m_end = v4;
      if ( v4 > this->m_max_end
        && !`vostok::buffer_vector<survarium::squad_member_item>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        v12 = 0;
        vostok::debug::on_error(
          &v12,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct survarium::squad_member_item>::resize",
          (const char *)0x98,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || v12 )
          __debugbreak();
      }
    }
  }
}


void __usercall vostok::buffer_vector<vostok::render::ui::vertex>::resize(
        vostok::buffer_vector<vostok::render::ui::vertex> *this@<esi>,
        unsigned int size@<eax>)
{
  vostok::render::ui::vertex *m_begin; // ecx
  unsigned int v3; // ebx
  vostok::render::ui::vertex *v4; // eax
  unsigned int v5; // edi
  vostok::render::ui::vertex *v6; // ecx
  vostok::render::ui::vertex *v7; // ebx
  float v8; // xmm0_4
  vostok::render::ui::vertex *v9; // edx
  vostok::render::ui::vertex *i; // eax
  const char *v11; // [esp+0h] [ebp-10h]
  bool do_debug_break; // [esp+Fh] [ebp-1h] BYREF

  m_begin = this->m_begin;
  v3 = this->m_end - this->m_begin;
  if ( size != v3 )
  {
    if ( size >= v3 )
    {
      v5 = size;
      if ( &m_begin[size] > this->m_max_end
        && !BYTE3(vostok::testing::suite_base<vostok::engine_test_suite>::s_suite_creation_flag.m_mutex[1]) )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct vostok::render::ui::vertex>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v11);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
      v6 = &this->m_begin[v5];
      v7 = &this->m_begin[v3];
      if ( v7 != v6 )
      {
        v8 = SNaN;
        v9 = v7 + 1;
        do
        {
          for ( i = v7; i != v9; ++i )
          {
            if ( i )
            {
              i->m_uv.x = v8;
              i->m_uv.y = v8;
            }
          }
          ++v7;
          ++v9;
        }
        while ( v7 != v6 );
      }
      this->m_end = &this->m_begin[v5];
    }
    else
    {
      v4 = &m_begin[size];
      this->m_end = v4;
      if ( v4 > this->m_max_end
        && !BYTE2(vostok::testing::suite_base<vostok::engine_test_suite>::s_suite_creation_flag.m_mutex[1]) )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct vostok::render::ui::vertex>::resize",
          (const char *)0x98,
          "buffer overflow",
          v11);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
  }
}


void __usercall vostok::buffer_vector<vostok::render::vertex_colored>::resize(
        vostok::buffer_vector<vostok::render::vertex_colored> *this@<edi>,
        unsigned int size@<eax>)
{
  vostok::render::vertex_colored *m_begin; // ecx
  unsigned int v3; // esi
  vostok::render::vertex_colored *v4; // eax
  unsigned int v5; // ebx
  vostok::render::vertex_colored *v6; // ecx
  vostok::render::vertex_colored *v7; // esi
  vostok::render::vertex_colored *v8; // edx
  vostok::render::vertex_colored *i; // eax
  const char *v10; // [esp+0h] [ebp-10h]
  bool do_debug_break; // [esp+Fh] [ebp-1h] BYREF

  m_begin = this->m_begin;
  v3 = this->m_end - this->m_begin;
  if ( size != v3 )
  {
    if ( size >= v3 )
    {
      v5 = size;
      if ( &m_begin[size] > this->m_max_end
        && !`vostok::buffer_vector<vostok::render::vertex_colored>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct vostok::render::vertex_colored>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
      v6 = &this->m_begin[v5];
      v7 = &this->m_begin[v3];
      if ( v7 != v6 )
      {
        v8 = v7 + 1;
        do
        {
          for ( i = v7; i != v8; ++i )
          {
            if ( i )
              i->color.m_value = -1;
          }
          ++v7;
          ++v8;
        }
        while ( v7 != v6 );
      }
      this->m_end = &this->m_begin[v5];
    }
    else
    {
      v4 = &m_begin[size];
      this->m_end = v4;
      if ( v4 > this->m_max_end
        && !`vostok::buffer_vector<vostok::render::vertex_colored>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct vostok::render::vertex_colored>::resize",
          (const char *)0x98,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
  }
}


void __usercall vostok::buffer_vector<survarium::victory_items_container::victory_item_transform>::resize(
        vostok::buffer_vector<survarium::victory_items_container::victory_item_transform> *this@<ecx>,
        int *a2@<esi>)
{
  int v2; // ecx
  unsigned int v3; // edi
  int v4; // edx
  int v5; // edi
  _DWORD *v6; // ecx
  _DWORD *v7; // eax
  const char *v8; // [esp+0h] [ebp-10h]
  bool v9; // [esp+Fh] [ebp-1h] BYREF

  v2 = *a2;
  v3 = (a2[1] - *a2) / 24;
  if ( v3 != 10 )
  {
    if ( v3 <= 0xA )
    {
      if ( v2 + 240 > (unsigned int)a2[2]
        && !`vostok::buffer_vector<survarium::victory_items_container::victory_item_transform>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        v9 = 0;
        vostok::debug::on_error(
          &v9,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct survarium::victory_items_container::victory_item_transform>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v8);
        if ( vostok::debug::is_debugger_present() || v9 )
          __debugbreak();
      }
      v4 = *a2 + 240;
      v5 = *a2 + 24 * v3;
      if ( v5 != v4 )
      {
        v6 = (_DWORD *)(v5 + 24);
        do
        {
          if ( (_DWORD *)v5 != v6 )
          {
            v7 = v6 - 1;
            do
            {
              if ( v7 != (_DWORD *)20 )
              {
                *(v7 - 5) = 0;
                *(v7 - 4) = 0;
                *(v7 - 3) = 0;
                *(v7 - 2) = 0;
                *(v7 - 1) = 0;
                *v7 = 0;
              }
              v7 += 6;
            }
            while ( v7 - 5 != v6 );
          }
          v5 += 24;
          v6 += 6;
        }
        while ( v5 != v4 );
      }
      a2[1] = *a2 + 240;
    }
    else
    {
      a2[1] = v2 + 240;
      if ( v2 + 240 > (unsigned int)a2[2]
        && !`vostok::buffer_vector<survarium::victory_items_container::victory_item_transform>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        v9 = 0;
        vostok::debug::on_error(
          &v9,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct survarium::victory_items_container::victory_item_transform>::resize",
          (const char *)0x98,
          "buffer overflow",
          v8);
        if ( vostok::debug::is_debugger_present() || v9 )
          __debugbreak();
      }
    }
  }
}


void __thiscall vostok::buffer_vector<survarium::victory_items_container::victory_item_transform>::resize(
        vostok::buffer_vector<survarium::victory_items_container::victory_item_transform> *this,
        _DWORD *size,
        const survarium::victory_items_container::victory_item_transform *value)
{
  _DWORD *v3; // ebx
  int v4; // ecx
  unsigned int v5; // esi
  int v6; // edx
  char *i; // eax
  const char *v8; // [esp+0h] [ebp-10h]

  v3 = size;
  v4 = *size;
  v5 = (size[1] - *size) / 24;
  if ( v5 != 10 )
  {
    if ( v5 <= 0xA )
    {
      if ( (unsigned int)(v4 + 240) > size[2]
        && !`vostok::buffer_vector<survarium::victory_items_container::victory_item_transform>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct survarium::victory_items_container::victory_item_transform>::resize",
          (const char *)0xB7,
          "buffer overflow",
          v8);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
      v6 = *v3 + 240;
      for ( i = (char *)(*v3 + 24 * v5); i != (char *)v6; i += 24 )
      {
        if ( i )
          qmemcpy(i, value, 0x18u);
      }
      v3[1] = *v3 + 240;
    }
    else
    {
      size[1] = v4 + 240;
      if ( (unsigned int)(v4 + 240) > v3[2]
        && !`vostok::buffer_vector<survarium::victory_items_container::victory_item_transform>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct survarium::victory_items_container::victory_item_transform>::resize",
          (const char *)0xB0,
          "buffer overflow",
          v8);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
    }
  }
}


void __userpurge vostok::buffer_vector<vostok::render::buffer_slot>::resize(
        vostok::buffer_vector<vostok::render::buffer_slot> *this@<ecx>,
        int *a2@<edi>,
        unsigned int size)
{
  int v3; // ecx
  unsigned int v4; // ebx
  unsigned int v5; // esi
  int v6; // esi
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *i; // ebx
  unsigned int v8; // eax
  unsigned int v9; // ebx
  int v10; // eax
  const char *v11; // [esp+0h] [ebp-Ch]

  v3 = *a2;
  v4 = size;
  v5 = (a2[1] - *a2) / 84;
  if ( size != v5 )
  {
    if ( size >= v5 )
    {
      v9 = 84 * size;
      if ( 84 * size + v3 > a2[2]
        && !`vostok::buffer_vector<vostok::render::buffer_slot>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::render::buffer_slot>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v11);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
      v10 = *a2;
      size = v9 + *a2;
      vostok::buffer_vector<vostok::render::buffer_slot>::construct(
        (vostok::render::buffer_slot *)(v10 + 84 * v5),
        (vostok::render::buffer_slot *const *)&size);
      a2[1] = v9 + *a2;
    }
    else
    {
      size = v3 + 84 * v5;
      v6 = 84 * v4;
      for ( i = (vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(84 * v4 + v3);
            i != (vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)size;
            i += 21 )
      {
        vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(i + 20);
      }
      v8 = v6 + *a2;
      a2[1] = v8;
      if ( v8 > a2[2]
        && !`vostok::buffer_vector<vostok::render::buffer_slot>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::render::buffer_slot>::resize",
          (const char *)0x98,
          "buffer overflow",
          v11);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
    }
  }
}


void __usercall vostok::buffer_vector<vostok::math::float4x4>::resize(
        vostok::buffer_vector<vostok::math::float4x4> *this@<esi>,
        unsigned int size@<eax>)
{
  vostok::math::float4x4 *m_begin; // edx
  unsigned int v3; // ecx
  vostok::math::float4x4 *v4; // eax
  unsigned int v5; // edi
  const char *v6; // [esp+0h] [ebp-10h]
  bool v7; // [esp+Fh] [ebp-1h] BYREF

  m_begin = this->m_begin;
  v3 = this->m_end - this->m_begin;
  if ( size != v3 )
  {
    if ( size >= v3 )
    {
      v5 = size << 6;
      if ( &m_begin[size] > this->m_max_end
        && !`vostok::buffer_vector<vostok::math::float4x4>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        v7 = 0;
        vostok::debug::on_error(
          &v7,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::math::float4x4>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v6);
        if ( vostok::debug::is_debugger_present() || v7 )
          __debugbreak();
      }
      this->m_end = (vostok::math::float4x4 *)((char *)this->m_begin + v5);
    }
    else
    {
      v4 = &m_begin[size];
      this->m_end = v4;
      if ( v4 > this->m_max_end
        && !`vostok::buffer_vector<vostok::math::float4x4>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        v7 = 0;
        vostok::debug::on_error(
          &v7,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::math::float4x4>::resize",
          (const char *)0x98,
          "buffer overflow",
          v6);
        if ( vostok::debug::is_debugger_present() || v7 )
          __debugbreak();
      }
    }
  }
}


void __userpurge vostok::buffer_vector<vostok::math::float4x4>::resize(
        unsigned int size@<eax>,
        vostok::buffer_vector<vostok::math::float4x4> *this,
        const vostok::math::float4x4 *value)
{
  vostok::buffer_vector<vostok::math::float4x4> *v3; // ebx
  vostok::math::float4x4 *m_begin; // ecx
  unsigned int v5; // esi
  vostok::math::float4x4 *v6; // eax
  unsigned int v7; // edi
  vostok::math::float4x4 *v8; // edx
  vostok::math::float4x4 *i; // eax
  const char *v10; // [esp+0h] [ebp-10h]
  unsigned int v11; // [esp+Ch] [ebp-4h]

  v3 = this;
  m_begin = this->m_begin;
  v5 = this->m_end - this->m_begin;
  if ( size != v5 )
  {
    if ( size >= v5 )
    {
      v7 = size << 6;
      v11 = size << 6;
      if ( &m_begin[size] > this->m_max_end
        && !`vostok::buffer_vector<vostok::math::float4x4>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        HIBYTE(this) = 0;
        vostok::debug::on_error(
          (bool *)&this + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::math::float4x4>::resize",
          (const char *)0xB7,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || HIBYTE(this) )
          __debugbreak();
      }
      v8 = (vostok::math::float4x4 *)((char *)v3->m_begin + v7);
      for ( i = &v3->m_begin[v5]; i != v8; ++i )
      {
        if ( i )
        {
          qmemcpy(i, value, sizeof(vostok::math::float4x4));
          v7 = v11;
        }
      }
      v3->m_end = (vostok::math::float4x4 *)((char *)v3->m_begin + v7);
    }
    else
    {
      v6 = &m_begin[size];
      this->m_end = v6;
      if ( v6 > v3->m_max_end
        && !`vostok::buffer_vector<vostok::math::float4x4>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        HIBYTE(this) = 0;
        vostok::debug::on_error(
          (bool *)&this + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::math::float4x4>::resize",
          (const char *)0xB0,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || HIBYTE(this) )
          __debugbreak();
      }
    }
  }
}


void __userpurge vostok::buffer_vector<vostok::render::sampler_slot>::resize(
        vostok::buffer_vector<vostok::render::sampler_slot> *this@<ecx>,
        int *a2@<edi>,
        vostok::render::sampler_slot *size)
{
  int v3; // ecx
  unsigned int v4; // esi
  unsigned int v5; // eax
  int v6; // ebx
  int v7; // eax
  const char *v8; // [esp+0h] [ebp-Ch]

  v3 = *a2;
  v4 = (a2[1] - *a2) / 84;
  if ( size != (vostok::render::sampler_slot *)v4 )
  {
    if ( (unsigned int)size >= v4 )
    {
      v6 = 84 * (_DWORD)size;
      if ( 84 * (int)size + v3 > (unsigned int)a2[2]
        && !`vostok::buffer_vector<vostok::render::sampler_slot>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::render::sampler_slot>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v8);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
      v7 = *a2;
      size = (vostok::render::sampler_slot *)(v6 + *a2);
      vostok::buffer_vector<vostok::render::sampler_slot>::construct(
        (vostok::render::sampler_slot *)(v7 + 84 * v4),
        &size);
      a2[1] = v6 + *a2;
    }
    else
    {
      v5 = 84 * (_DWORD)size + v3;
      a2[1] = v5;
      if ( v5 > a2[2]
        && !`vostok::buffer_vector<vostok::render::sampler_slot>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::render::sampler_slot>::resize",
          (const char *)0x98,
          "buffer overflow",
          v8);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
    }
  }
}


void __userpurge vostok::buffer_vector<vostok::render::texture_slot>::resize(
        vostok::buffer_vector<vostok::render::texture_slot> *this@<ecx>,
        int *a2@<edi>,
        unsigned int size)
{
  int v3; // ecx
  unsigned int v4; // ebx
  unsigned int v5; // esi
  int v6; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *i; // ebx
  unsigned int v8; // eax
  unsigned int v9; // ebx
  int v10; // eax
  const char *v11; // [esp+0h] [ebp-Ch]

  v3 = *a2;
  v4 = size;
  v5 = (a2[1] - *a2) / 84;
  if ( size != v5 )
  {
    if ( size >= v5 )
    {
      v9 = 84 * size;
      if ( 84 * size + v3 > a2[2]
        && !`vostok::buffer_vector<vostok::render::texture_slot>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::render::texture_slot>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v11);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
      v10 = *a2;
      size = v9 + *a2;
      vostok::buffer_vector<vostok::render::texture_slot>::construct(
        (vostok::render::texture_slot *)(v10 + 84 * v5),
        (vostok::render::texture_slot *const *)&size);
      a2[1] = v9 + *a2;
    }
    else
    {
      size = v3 + 84 * v5;
      v6 = 84 * v4;
      for ( i = (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(84 * v4 + v3);
            i != (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)size;
            i += 21 )
      {
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(i + 20);
      }
      v8 = v6 + *a2;
      a2[1] = v8;
      if ( v8 > a2[2]
        && !`vostok::buffer_vector<vostok::render::texture_slot>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::render::texture_slot>::resize",
          (const char *)0x98,
          "buffer overflow",
          v11);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
    }
  }
}


void __userpurge vostok::buffer_vector<vostok::tasks::thread_tls>::resize(
        vostok::buffer_vector<vostok::tasks::thread_tls> *this@<ecx>,
        int *a2@<esi>,
        unsigned int size)
{
  int v3; // ecx
  unsigned int v4; // ebx
  unsigned int v5; // edi
  unsigned int v6; // eax
  unsigned int v7; // ebx
  int v8; // eax
  const char *v9; // [esp+0h] [ebp-Ch]

  v3 = *a2;
  v4 = size;
  v5 = (a2[1] - *a2) / 360;
  if ( size != v5 )
  {
    if ( size >= v5 )
    {
      v7 = 360 * size;
      if ( 360 * size + v3 > a2[2]
        && !`vostok::buffer_vector<vostok::tasks::thread_tls>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::tasks::thread_tls>::resize",
          (const char *)0x9F,
          "buffer overflow",
          v9);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
      v8 = *a2;
      size = v7 + *a2;
      vostok::buffer_vector<vostok::tasks::thread_tls>::construct(
        (vostok::tasks::thread_tls *)(v8 + 360 * v5),
        (vostok::tasks::thread_tls **)&size);
      a2[1] = v7 + *a2;
    }
    else
    {
      size = v3 + 360 * v5;
      vostok::buffer_vector<vostok::tasks::thread_tls>::destroy(
        (vostok::tasks::thread_tls *)(360 * v4 + v3),
        (vostok::tasks::thread_tls **)&size);
      v6 = 360 * v4 + *a2;
      a2[1] = v6;
      if ( v6 > a2[2]
        && !`vostok::buffer_vector<vostok::tasks::thread_tls>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::tasks::thread_tls>::resize",
          (const char *)0x98,
          "buffer overflow",
          v9);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
    }
  }
}


void __userpurge vostok::buffer_vector<survarium::fixed_history<survarium::player_input_history_item,27>>::resize(
        vostok::buffer_vector<survarium::fixed_history<survarium::player_input_history_item,27> > *this@<ecx>,
        boost::function1<void,vostok::sound::create_sound_propagator_params const &> **a2@<esi>,
        unsigned int size)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  unsigned int v4; // ebx
  unsigned int v5; // edi
  unsigned int v6; // eax
  unsigned int v7; // ebx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // eax
  const char *v9; // [esp+0h] [ebp-Ch]

  v3 = *a2;
  v4 = size;
  v5 = ((char *)a2[1] - (char *)*a2) / 720;
  if ( size != v5 )
  {
    if ( size >= v5 )
    {
      v7 = 720 * size;
      if ( (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)((char *)v3 + 720 * size) > a2[2]
        && !`vostok::buffer_vector<survarium::fixed_history<survarium::player_input_history_item,27>>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class survarium::fixed_history<struct survarium::player_input_history_item,27> >::resize",
          (const char *)0x9F,
          "buffer overflow",
          v9);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
      v8 = *a2;
      size = (unsigned int)*a2 + v7;
      vostok::buffer_vector<survarium::fixed_history<survarium::player_input_history_item,27>>::construct(
        (survarium::fixed_history<survarium::player_input_history_item,27> *)v8 + v5,
        (survarium::fixed_history<survarium::player_input_history_item,27> **)&size);
      a2[1] = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)((char *)*a2 + v7);
    }
    else
    {
      size = (unsigned int)v3 + 720 * v5;
      vostok::buffer_vector<survarium::fixed_history<survarium::player_input_history_item,27>>::destroy(
        (survarium::fixed_history<survarium::player_input_history_item,27> *)v3 + v4,
        v3,
        (survarium::fixed_history<survarium::player_input_history_item,27> **)&size);
      v6 = (unsigned int)*a2 + 720 * v4;
      a2[1] = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v6;
      if ( v6 > (unsigned int)a2[2]
        && !`vostok::buffer_vector<survarium::fixed_history<survarium::player_input_history_item,27>>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class survarium::fixed_history<struct survarium::player_input_history_item,27> >::resize",
          (const char *)0x98,
          "buffer overflow",
          v9);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
    }
  }
}


void __userpurge vostok::buffer_vector<vostok::fixed_string<32>>::resize(
        vostok::buffer_vector<vostok::fixed_string<32> > *this@<ecx>,
        int *a2@<esi>,
        unsigned int size)
{
  int v3; // ecx
  unsigned int v4; // edi
  unsigned int v5; // eax
  unsigned int v6; // ebx
  int v7; // edi
  _BYTE *v8; // ecx
  _BYTE *v9; // eax
  const char *v10; // [esp+0h] [ebp-Ch]

  v3 = *a2;
  v4 = (a2[1] - *a2) / 44;
  if ( size != v4 )
  {
    if ( size >= v4 )
    {
      v6 = 44 * size;
      if ( 44 * size + v3 > a2[2]
        && !`vostok::buffer_vector<vostok::fixed_string<32>>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::fixed_string<32> >::resize",
          (const char *)0x9F,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
      v7 = *a2 + 44 * v4;
      size = v6 + *a2;
      if ( v7 != size )
      {
        v8 = (_BYTE *)(v7 + 44);
        do
        {
          if ( (_BYTE *)v7 != v8 )
          {
            v9 = v8 - 32;
            do
            {
              if ( v9 != (_BYTE *)12 )
              {
                *((_DWORD *)v9 - 3) = v9;
                *((_DWORD *)v9 - 2) = v9;
                *((_DWORD *)v9 - 1) = v9 + 32;
                *v9 = 0;
                *v9 = 0;
              }
              v9 += 44;
            }
            while ( v9 - 12 != v8 );
          }
          v7 += 44;
          v8 += 44;
        }
        while ( v7 != size );
      }
      a2[1] = v6 + *a2;
    }
    else
    {
      v5 = 44 * size + v3;
      a2[1] = v5;
      if ( v5 > a2[2]
        && !`vostok::buffer_vector<vostok::fixed_string<32>>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::fixed_string<32> >::resize",
          (const char *)0x98,
          "buffer overflow",
          v10);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
    }
  }
}


void __userpurge vostok::buffer_vector<vostok::fixed_vector<vostok::render::culling::aab_rect,1024>>::resize(
        vostok::buffer_vector<vostok::fixed_vector<vostok::render::culling::aab_rect,1024> > *this@<ecx>,
        int *a2@<esi>,
        vostok::fixed_vector<vostok::render::culling::aab_rect,1024> *size)
{
  int v3; // ecx
  unsigned int v4; // edi
  int v5; // eax
  _DWORD *v6; // edi
  _DWORD *i; // ecx
  unsigned int v8; // eax
  int v9; // ebx
  vostok::fixed_vector<vostok::render::culling::aab_rect,1024> *v10; // edx
  const char *v11; // [esp+0h] [ebp-Ch]

  v3 = *a2;
  v4 = (a2[1] - *a2) / 16396;
  if ( size != (vostok::fixed_vector<vostok::render::culling::aab_rect,1024> *)v4 )
  {
    if ( (unsigned int)size >= v4 )
    {
      v9 = 16396 * (_DWORD)size;
      if ( 16396 * (int)size + v3 > (unsigned int)a2[2]
        && !`vostok::buffer_vector<vostok::fixed_vector<vostok::render::culling::aab_rect,1024>>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::fixed_vector<class vostok::render::culling::aab_rect,1024> >::resize",
          (const char *)0x9F,
          "buffer overflow",
          v11);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
      v10 = (vostok::fixed_vector<vostok::render::culling::aab_rect,1024> *)(*a2 + 16396 * v4);
      size = (vostok::fixed_vector<vostok::render::culling::aab_rect,1024> *)(v9 + *a2);
      vostok::buffer_vector<vostok::fixed_vector<vostok::render::culling::aab_rect,1024>>::construct(v10, &size);
      a2[1] = v9 + *a2;
    }
    else
    {
      v5 = 16396 * (_DWORD)size;
      v6 = (_DWORD *)(v3 + 16396 * v4);
      for ( i = (_DWORD *)(16396 * (_DWORD)size + v3); i != v6; i += 4099 )
        i[1] = *i;
      v8 = *a2 + v5;
      a2[1] = v8;
      if ( v8 > a2[2]
        && !`vostok::buffer_vector<vostok::fixed_vector<vostok::render::culling::aab_rect,1024>>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::fixed_vector<class vostok::render::culling::aab_rect,1024> >::resize",
          (const char *)0x98,
          "buffer overflow",
          v11);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
    }
  }
}


void __userpurge vostok::buffer_vector<vostok::fixed_vector<vostok::math::frustum,1024>>::resize(
        vostok::buffer_vector<vostok::fixed_vector<vostok::math::frustum,1024> > *this@<ecx>,
        int *a2@<esi>,
        vostok::fixed_vector<vostok::math::frustum,1024> *size)
{
  int v3; // ecx
  unsigned int v4; // edi
  int v5; // eax
  _DWORD *v6; // edi
  _DWORD *i; // ecx
  unsigned int v8; // eax
  int v9; // ebx
  vostok::fixed_vector<vostok::math::frustum,1024> *v10; // edx
  const char *v11; // [esp+0h] [ebp-Ch]

  v3 = *a2;
  v4 = (a2[1] - *a2) / ((int)&loc_1E00A + 2);
  if ( size != (vostok::fixed_vector<vostok::math::frustum,1024> *)v4 )
  {
    if ( (unsigned int)size >= v4 )
    {
      v9 = 122892 * (_DWORD)size;
      if ( 122892 * (int)size + v3 > (unsigned int)a2[2]
        && !`vostok::buffer_vector<vostok::fixed_vector<vostok::math::frustum,1024>>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::fixed_vector<class vostok::math::frustum,1024> >::resize",
          (const char *)0x9F,
          "buffer overflow",
          v11);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
      v10 = (vostok::fixed_vector<vostok::math::frustum,1024> *)(*a2 + 122892 * v4);
      size = (vostok::fixed_vector<vostok::math::frustum,1024> *)(v9 + *a2);
      vostok::buffer_vector<vostok::fixed_vector<vostok::math::frustum,1024>>::construct(v10, &size);
      a2[1] = v9 + *a2;
    }
    else
    {
      v5 = 122892 * (_DWORD)size;
      v6 = (_DWORD *)(v3 + 122892 * v4);
      for ( i = (_DWORD *)(122892 * (_DWORD)size + v3); i != v6; i = (_DWORD *)((char *)i + (_DWORD)&loc_1E00A + 2) )
        i[1] = *i;
      v8 = *a2 + v5;
      a2[1] = v8;
      if ( v8 > a2[2]
        && !`vostok::buffer_vector<vostok::fixed_vector<vostok::math::frustum,1024>>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        HIBYTE(size) = 0;
        vostok::debug::on_error(
          (bool *)&size + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::fixed_vector<class vostok::math::frustum,1024> >::resize",
          (const char *)0x98,
          "buffer overflow",
          v11);
        if ( vostok::debug::is_debugger_present() || HIBYTE(size) )
          __debugbreak();
      }
    }
  }
}


void __usercall vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::resize(
        vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *this@<ecx>,
        int *a2@<edi>)
{
  int v2; // eax
  unsigned int v3; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v4; // edx
  int v5; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v6; // ebx
  unsigned int v7; // eax
  int v8; // ebx
  int v9; // edx
  int v10; // eax
  _DWORD *v11; // esi
  _DWORD *i; // ecx
  const char *v13; // [esp+0h] [ebp-10h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *j; // [esp+8h] [ebp-8h]
  bool v15; // [esp+Fh] [ebp-1h] BYREF

  v2 = *a2;
  v3 = (a2[1] - *a2) >> 2;
  if ( this != (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)v3 )
  {
    if ( (unsigned int)this >= v3 )
    {
      v8 = 4 * (_DWORD)this;
      if ( 4 * (int)this + v2 > (unsigned int)a2[2]
        && !`vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        v15 = 0;
        vostok::debug::on_error(
          &v15,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::intrusive_ptr<class vostok::render::res_texture,class vostok::render::reso"
          "urce_intrusive_base,class vostok::threading::single_threading_policy> >::resize",
          (const char *)0x9F,
          "buffer overflow",
          v13);
        if ( vostok::debug::is_debugger_present() || v15 )
          __debugbreak();
      }
      v9 = v8 + *a2;
      v10 = *a2 + 4 * v3;
      if ( v10 != v9 )
      {
        v11 = (_DWORD *)(v10 + 4);
        do
        {
          for ( i = (_DWORD *)v10; i != v11; ++i )
          {
            if ( i )
              *i = 0;
          }
          v10 += 4;
          ++v11;
        }
        while ( v10 != v9 );
      }
      a2[1] = v8 + *a2;
    }
    else
    {
      v4 = (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(v2 + 4 * v3);
      v5 = 4 * (_DWORD)this;
      v6 = (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(4 * (_DWORD)this + v2);
      for ( j = v4; v6 != j; ++v6 )
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(v6);
      v7 = v5 + *a2;
      a2[1] = v7;
      if ( v7 > a2[2]
        && !`vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        v15 = 0;
        vostok::debug::on_error(
          &v15,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::intrusive_ptr<class vostok::render::res_texture,class vostok::render::reso"
          "urce_intrusive_base,class vostok::threading::single_threading_policy> >::resize",
          (const char *)0x98,
          "buffer overflow",
          v13);
        if ( vostok::debug::is_debugger_present() || v15 )
          __debugbreak();
      }
    }
  }
}


void __usercall vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::resize(
        vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *this@<ecx>,
        int *a2@<edi>)
{
  int v2; // eax
  unsigned int v3; // esi
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v4; // edx
  int v5; // esi
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v6; // ebx
  unsigned int v7; // eax
  int v8; // ebx
  int v9; // edx
  int v10; // eax
  _DWORD *v11; // esi
  _DWORD *i; // ecx
  const char *v13; // [esp+0h] [ebp-10h]
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *j; // [esp+8h] [ebp-8h]
  bool v15; // [esp+Fh] [ebp-1h] BYREF

  v2 = *a2;
  v3 = (a2[1] - *a2) >> 2;
  if ( this != (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)v3 )
  {
    if ( (unsigned int)this >= v3 )
    {
      v8 = 4 * (_DWORD)this;
      if ( 4 * (int)this + v2 > (unsigned int)a2[2]
        && !`vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        v15 = 0;
        vostok::debug::on_error(
          &v15,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::intrusive_ptr<class vostok::render::shader_buffer,class vostok::render::re"
          "source_intrusive_base,class vostok::threading::single_threading_policy> >::resize",
          (const char *)0x9F,
          "buffer overflow",
          v13);
        if ( vostok::debug::is_debugger_present() || v15 )
          __debugbreak();
      }
      v9 = v8 + *a2;
      v10 = *a2 + 4 * v3;
      if ( v10 != v9 )
      {
        v11 = (_DWORD *)(v10 + 4);
        do
        {
          for ( i = (_DWORD *)v10; i != v11; ++i )
          {
            if ( i )
              *i = 0;
          }
          v10 += 4;
          ++v11;
        }
        while ( v10 != v9 );
      }
      a2[1] = v8 + *a2;
    }
    else
    {
      v4 = (vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(v2 + 4 * v3);
      v5 = 4 * (_DWORD)this;
      v6 = (vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(4 * (_DWORD)this + v2);
      for ( j = v4; v6 != j; ++v6 )
        vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(v6);
      v7 = v5 + *a2;
      a2[1] = v7;
      if ( v7 > a2[2]
        && !`vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        v15 = 0;
        vostok::debug::on_error(
          &v15,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::intrusive_ptr<class vostok::render::shader_buffer,class vostok::render::re"
          "source_intrusive_base,class vostok::threading::single_threading_policy> >::resize",
          (const char *)0x98,
          "buffer overflow",
          v13);
        if ( vostok::debug::is_debugger_present() || v15 )
          __debugbreak();
      }
    }
  }
}


void __usercall vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>::resize(
        vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *this@<ecx>,
        const char *a2@<ebx>,
        int *a3@<edi>)
{
  int v3; // eax
  unsigned int v4; // esi
  int *v5; // edx
  int v6; // esi
  int *v7; // ebx
  unsigned int v8; // eax
  int v9; // ebx
  int v10; // edx
  int v11; // eax
  _DWORD *v12; // esi
  _DWORD *i; // ecx
  int *j; // [esp+4h] [ebp-8h]
  bool v16; // [esp+Bh] [ebp-1h] BYREF

  v3 = *a3;
  v4 = (a3[1] - *a3) >> 2;
  if ( this != (vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)v4 )
  {
    if ( (unsigned int)this >= v4 )
    {
      v9 = 4 * (_DWORD)this;
      if ( 4 * (int)this + v3 > (unsigned int)a3[2]
        && !`vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>::resize'::`38'::debug_macro_helper_ignore_always )
      {
        v16 = 0;
        vostok::debug::on_error(
          &v16,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::physics::loose_ptr<class vostok::physics::base_physics_object,class vostok"
          "::physics::loose_ptr_data,class vostok::threading::multi_threading_policy> >::resize",
          (const char *)0x9F,
          "buffer overflow",
          a2);
        if ( vostok::debug::is_debugger_present() || v16 )
          __debugbreak();
      }
      v10 = v9 + *a3;
      v11 = *a3 + 4 * v4;
      if ( v11 != v10 )
      {
        v12 = (_DWORD *)(v11 + 4);
        do
        {
          for ( i = (_DWORD *)v11; i != v12; ++i )
          {
            if ( i )
              *i = 0;
          }
          v11 += 4;
          ++v12;
        }
        while ( v11 != v10 );
      }
      a3[1] = v9 + *a3;
    }
    else
    {
      v5 = (int *)(v3 + 4 * v4);
      v6 = 4 * (_DWORD)this;
      v7 = (int *)(4 * (_DWORD)this + v3);
      for ( j = v5; v7 != j; ++v7 )
        vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>::dec(
          (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)this,
          v7);
      v8 = v6 + *a3;
      a3[1] = v8;
      if ( v8 > a3[2]
        && !`vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>::resize'::`16'::debug_macro_helper_ignore_always )
      {
        v16 = 0;
        vostok::debug::on_error(
          &v16,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<class vostok::physics::loose_ptr<class vostok::physics::base_physics_object,class vostok"
          "::physics::loose_ptr_data,class vostok::threading::multi_threading_policy> >::resize",
          (const char *)0x98,
          "buffer overflow",
          a2);
        if ( vostok::debug::is_debugger_present() || v16 )
          __debugbreak();
      }
    }
  }
}
