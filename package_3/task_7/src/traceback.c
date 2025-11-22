#include "traceback.h"

int write_trace(interpretator_state *state, const char *operation_desc) {
    fprintf(state->trace_file, "[%d] %s | ", state->line_number, state->current_str);
    
    for (size_t i = 0; i < state->vs.size; i++) {
        fprintf(state->trace_file, "%c=%d", state->vs.data[i].name, state->vs.data[i].value);
        if (i < state->vs.size - 1) fprintf(state->trace_file, ", ");
    }
    
    fprintf(state->trace_file, " | %s\n", operation_desc);
    return 0;
}
