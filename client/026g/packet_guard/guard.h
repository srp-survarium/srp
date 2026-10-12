#ifndef SRP_026_PACKET_GUARD_H
#define SRP_026_PACKET_GUARD_H
#include <stddef.h>
#include <stdint.h>
#if defined(_MSC_VER)
#define PG_CALL __cdecl
#elif defined(__i386__) && defined(__GNUC__)
#define PG_CALL __attribute__((cdecl))
#else
#define PG_CALL
#endif
#ifdef __cplusplus
extern "C" {
#endif

/* Implementation: Rust no_std. Pointers must refer to live memory of the stated
 * size. Outputs, contexts and scratch must not alias input or each other.
 * Callbacks are pure, synchronous, and must not unwind. Null byte pointers are
 * accepted only with size zero. Null callbacks reject unmapped schemas.
 * Transport/envelope success is NOT application dispatch approval.
 */
enum pg_status {
    PG_OK = 0, PG_TRUNCATED = 1, PG_LIMIT = 2, PG_INVALID = 3,
    PG_UNSUPPORTED = 4, PG_FRAGMENT_PENDING = 5, PG_FRAGMENT_CONFLICT = 6,
    PG_EXPIRED = 7, PG_CODEC_ERROR = 8, PG_MORE = 9
};
enum pg_channel { PG_LOBBY = 1, PG_MATCH = 2 };
enum pg_login_stage { PG_LOGIN_NAME_REPLY = 1, PG_LOGIN_PASSWORD_REPLY = 2 };
enum pg_state_part {
    PG_PLAYER_STATE = 1, PG_ANIMATION_TREE = 2, PG_BULLETS = 3,
    PG_STATISTICS = 4, PG_OBJECTS = 5, PG_PHYSICS = 6, PG_RULES = 7,
    PG_EFFECTS = 8, PG_ANIMATION_VALUES = 9
};
enum {
    PG_MAX_DATAGRAM = 512, PG_MAX_FRAMES = 252, PG_MAX_PARTS = 255,
    PG_MAX_MESSAGE = 130560, PG_MAX_OPTIONS = 358560, PG_MAX_STATE = 32768,
    PG_MAX_PLAYERS = 20, PG_MAX_FRAGMENT_MS = 5000, PG_ABSENT = 256
};

/* Host allocator for the bounded Rust decoder: suitably aligned distinct
 * storage, or null on failure. Free receives original size/alignment. Abort
 * must terminate, never return/unwind. Implementations must support concurrency.
 */
void *PG_CALL pg_host_alloc(size_t size, size_t alignment);
void PG_CALL pg_host_free(void *memory, size_t size, size_t alignment);
void PG_CALL pg_host_abort(void);

typedef uint32_t (PG_CALL *pg_item_kind_fn)(void *, uint32_t dictionary_id);
typedef uint32_t (PG_CALL *pg_map_exists_fn)(void *, uint32_t map_id);
typedef int32_t (PG_CALL *pg_message_schema_fn)(void *, uint32_t opcode, const uint8_t *, uint32_t size);
typedef int32_t (PG_CALL *pg_state_schema_fn)(void *, uint32_t part, const uint8_t *,
                                     uint32_t size, uint32_t meaningful_bits, uint32_t slot);
struct pg_callbacks {
    void *context;
    pg_item_kind_fn item_kind; /* 1 stackable, 2 non-stackable, 0 unknown */
    pg_map_exists_fn map_exists; /* exactly 1 for known local map */
    pg_message_schema_fn lobby_schema;
    pg_message_schema_fn match_schema;
    pg_state_schema_fn state_schema; /* slot=20 for non-player block */
};
struct pg_frame {
    uint32_t opcode, delivery, index, count;
    const uint8_t *body;
    uint32_t size;
    /* delivery/index=PG_ABSENT when absent; count=0 unless fragment zero. */
};

int32_t PG_CALL pg_login(uint32_t stage, const uint8_t *, uint32_t size);
uint32_t PG_CALL pg_login_size(void);
uint32_t PG_CALL pg_login_align(void);
int32_t PG_CALL pg_login_init(void *context, uint32_t context_size);
/* PG_MORE retains partial input. PG_OK response borrows context until its next
 * call. Apply the stage transition before feeding unconsumed bytes. Close/reset
 * on error; never call the native reader on an incomplete response.
 */
int32_t PG_CALL pg_login_feed(void *, uint32_t context_size, uint32_t stage,
                      const uint8_t *, uint32_t size, uint32_t *consumed,
                      const uint8_t **response, uint32_t *response_size);
/* Full datagram -> transport frames. players=0 before roster is known.
 * written=0 on failure; output frame bodies borrow the input buffer.
 */
int32_t PG_CALL pg_udp(uint32_t channel, uint32_t players, const uint8_t *, uint32_t size,
               struct pg_frame *, uint32_t capacity, uint32_t *written);
uint32_t PG_CALL pg_reassembly_size(void);
uint32_t PG_CALL pg_reassembly_align(void);
int32_t PG_CALL pg_reassembly_init(void *, uint32_t context_size);
/* Output is valid only on PG_OK; borrows context until its next use/reset. */
int32_t PG_CALL pg_reassemble(void *, uint32_t context_size, uint32_t channel,
                      const struct pg_frame *, uint32_t now_ms, struct pg_frame *out);
int32_t PG_CALL pg_lobby(uint32_t opcode, const uint8_t *, uint32_t size, const struct pg_callbacks *);
int32_t PG_CALL pg_match(uint32_t opcode, const uint8_t *, uint32_t size, uint32_t players,
                 const struct pg_callbacks *, uint8_t *scratch, uint32_t scratch_size,
                 uint32_t *new_roster);
int32_t PG_CALL pg_options(const uint8_t *, uint32_t size, const struct pg_callbacks *, uint32_t *new_roster);
/* Diagnostic boundary check only; never authorizes native dispatch. */
int32_t PG_CALL pg_state_envelope(const uint8_t *, uint32_t size, uint32_t players);
int32_t PG_CALL pg_state_deep(const uint8_t *, uint32_t size, uint32_t players, const struct pg_callbacks *);
int32_t PG_CALL pg_decode(const uint8_t *, uint32_t size, uint8_t *out, uint32_t capacity, uint32_t *written);

#ifdef __cplusplus
}
#endif
#endif
