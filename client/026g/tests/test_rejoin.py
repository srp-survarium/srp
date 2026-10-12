# SPDX-License-Identifier: GPL-3.0-or-later
"""Exercise the actual rejoin policy with only the three native calls replaced."""
import ctypes
import os
from pathlib import Path
import subprocess
import tempfile
import unittest

HARNESS = r'''
#include <string.h>
static _Alignas(8) unsigned char storage[512];
static unsigned char lobby[0x3140], game[0x53c0], network[0x1f1c60], match[0x577c0];
static int calls, disconnected, counter_ok;
static unsigned int got_port, got_match, got_session;
static char got_host[256];
static char session_token[64];
static unsigned int environment(const char *name, char *out, unsigned int size) {
    if (strcmp(name,"SRP_MATCH_SESSION")) return 0;
    unsigned int len = strlen(session_token);
    if (len < size) memcpy(out,session_token,len+1);
    return len < size ? len : len+1;
}
static int counter(unsigned long long *out) { *out = 42; return counter_ok; }
static int is_disconnected(void *p) { return p == match && disconnected; }
static void connect_match(void *p, const char *host, unsigned short port,
                          unsigned int id, unsigned int session) {
    if (p != network) return;
    ++calls; strcpy(got_host, host); got_port=port; got_match=id; got_session=session;
}
#define REJOIN_STATE storage
#define REJOIN_COUNTER counter
#define REJOIN_DISCONNECTED is_disconnected
#define REJOIN_CONNECT connect_match
#define REJOIN_ENVIRONMENT environment
#include "rejoin.c"
void fixture_reset(void) {
    memset(storage,0,sizeof(storage)); memset(lobby,0,sizeof(lobby));
    memset(game,0,sizeof(game)); memset(network,0,sizeof(network)); memset(match,0,sizeof(match));
    *(void **)(lobby+0x9c)=game; *(void **)(game+0x53ac)=network;
    *(void **)(network+0x1f1c48)=match; *(u32 *)(match+0x577bc)=7;
    calls=0; counter_ok=disconnected=1;
    got_port=got_match=got_session=0; got_host[0]=0; session_token[0]=0;
}
void fixture_token(const char *token) { strcpy(session_token,token); }
unsigned int fixture_session(unsigned int previous) { return rejoin_session(previous); }
void fixture_configure(const char *host, u32 port, u32 spectator) {
    rejoin_configure(game, host, port, spectator);
}
void fixture_complete(int correct) { rejoin_completed(correct ? game : lobby); }
int fixture_initial_results(void) { return rejoin_initial_results(game); }
int fixture_key(u32 key,u32 action) { return rejoin_keyboard(lobby,key,action); }
void fixture_guard(int which,int enabled) {
    if (which==0) lobby[0x313a]=enabled;
    if (which==1) *(void **)(network+0x1f1c40)=enabled ? game : 0;
    if (which==2) disconnected=!enabled;
    if (which==3) counter_ok=!enabled;
    if (which==4) *(void **)(game+0x53ac)=enabled ? 0 : network;
    if (which==5) *(void **)(network+0x1f1c48)=enabled ? 0 : match;
    if (which==6) *(void **)(lobby+0x9c)=enabled ? network : game;
}
unsigned int fixture_value(int which) {
    if(which==0)return calls; if(which==1)return got_port;
    if(which==2)return got_match; return got_session;
}
const char *fixture_host(void) { return got_host; }
'''


class RejoinPolicy(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.work = tempfile.TemporaryDirectory(prefix='srp-rejoin-tests-')
        cls.addClassCleanup(cls.work.cleanup)
        work = Path(cls.work.name)
        (work/'harness.c').write_text(HARNESS)
        source = Path(__file__).resolve().parents[1]/'tools'
        subprocess.run([os.environ.get('CC', 'cc'), '-shared', '-fPIC', '-O2',
                        '-Wno-attributes', '-I', str(source), str(work/'harness.c'),
                        '-o', str(work/'test.so')], check=True)
        cls.lib = ctypes.CDLL(str(work/'test.so'))
        cls.lib.fixture_configure.argtypes = [ctypes.c_char_p, ctypes.c_uint, ctypes.c_uint]
        cls.lib.fixture_host.restype = ctypes.c_char_p
        cls.lib.fixture_value.restype = ctypes.c_uint
        cls.lib.fixture_token.argtypes = [ctypes.c_char_p]
        cls.lib.fixture_session.restype = ctypes.c_uint

    def setUp(self):
        self.lib.fixture_reset()

    def ready(self, host=b'localhost', port=2239):
        self.lib.fixture_configure(host, port, 0)
        self.lib.fixture_complete(1)

    def press(self):
        self.lib.fixture_key(0x40, 1)
        self.lib.fixture_key(0x40, 2)

    def test_requires_completion_and_closed_disconnected_world(self):
        self.lib.fixture_configure(b'localhost', 2239, 0)
        self.assertEqual(self.lib.fixture_initial_results(), 1)
        self.press()
        self.lib.fixture_complete(0)
        self.assertEqual(self.lib.fixture_initial_results(), 1)
        self.press()
        self.assertEqual(self.lib.fixture_value(0), 0)
        self.lib.fixture_complete(1)
        self.assertEqual(self.lib.fixture_initial_results(), 0)
        for guard in range(7):
            self.lib.fixture_guard(guard, 1)
            self.press()
            self.assertEqual(self.lib.fixture_value(0), 0, guard)
            self.lib.fixture_guard(guard, 0)
        self.press()
        self.assertEqual(self.lib.fixture_value(0), 1)

    def test_copies_endpoint_and_rotates_session_without_repeating_held_key(self):
        host = ctypes.create_string_buffer(b'127.0.0.1')
        self.ready(host)
        host.value = b'localhost'
        self.lib.fixture_key(0x41, 1)
        self.assertEqual(self.lib.fixture_value(0), 0)
        self.lib.fixture_key(0x40, 1)
        for action in (1, 3, 1, 3):
            self.lib.fixture_key(0x40, action)
        self.assertEqual(self.lib.fixture_value(0), 1)
        self.assertEqual(self.lib.fixture_host(), b'127.0.0.1')
        self.assertEqual(self.lib.fixture_value(1), 2239)
        self.assertEqual(self.lib.fixture_value(2), 8)
        first_session = self.lib.fixture_value(3)
        self.assertNotEqual(first_session, 0)
        self.lib.fixture_key(0x40, 2)
        self.press()  # explicit retry after disconnect, even if the clock repeats
        self.assertEqual(self.lib.fixture_value(0), 2)
        self.assertNotEqual(self.lib.fixture_value(3), first_session)
        self.assertNotEqual(self.lib.fixture_value(3), 0)

    def test_endpoint_bounds_and_spectator_do_not_arm(self):
        for host, port, spectator in [(b'',2239,0),(b'x'*256,2239,0),
                (b'localhost',0,0),(b'localhost',65536,0),(b'localhost',2239,1)]:
            self.lib.fixture_reset()
            self.lib.fixture_configure(host,port,spectator)
            self.lib.fixture_complete(1)
            self.press()
            self.assertEqual(self.lib.fixture_value(0),0)
        self.ready(b'x'*255,65535)
        self.press()
        self.assertEqual(self.lib.fixture_value(0),1)
        self.assertEqual(self.lib.fixture_host(),b'x'*255)
        self.assertEqual(self.lib.fixture_value(1),65535)

    def test_configured_identity_survives_rejoin_and_invalid_values_do_not_connect(self):
        self.ready()
        self.lib.fixture_token(b'aB1234Cd')
        self.assertEqual(self.lib.fixture_session(0), 0xab1234cd)
        self.assertEqual(self.lib.fixture_session(0xab1234cd), 0xab1234cd)
        self.press()
        self.press()
        self.assertEqual(self.lib.fixture_value(0), 2)
        self.assertEqual(self.lib.fixture_value(3), 0xab1234cd)
        for bad in (b'00000000',b'123',b'0xabcdef',b'123456789',b'1234567z',b' 1234567'):
            self.lib.fixture_token(bad)
            self.assertEqual(self.lib.fixture_session(0),0)
            self.press()
            self.assertEqual(self.lib.fixture_value(0),2)


if __name__ == '__main__':
    unittest.main()
