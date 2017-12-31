## callo
We are building the core of peer-to-peer network for financial institution.
`We propose a solution to the double-spending problem using a peer-to-peer network. The network timestamps transactions by hashing them into an ongoing chain of hash-based proof-of-work, forming a record that cannot be changed without redoing the proof-of-work.  The longest chain not only serves as proof of the sequence of events witnessed, but proof that it came from the largest pool of CPU power.  As long as a majority òf CPU power is controlled by nodes that are not cooperating to attack the network, they will generate 
the longest chain and outpace attackers. The network itself requires miminal structure. Message are broadcast on a best effort basis,
and nodes can leave and rejoin the network at will, accepting the longest proof of work chain as proof-of-work chain as proof of what 
happenend while they were gone. `

# introduction
The fastest growing of internet has change many thing. In fact, that evelotion has change how we buy. the system works well enough for some transactions. but it suffers from latency and weaknesses of the trust based model. the latency is due to time transaction inside 
some region like africa where money transfert accross two country can take more than tree days. the weaknesses of trust based model is due to human interaction during transaction.
So, we need a elecctronic transfert system based on cryptographic proof instead trust, allowing any two willing parties to interact 
directly with each other without the need of the third party. Transactions that are computationally impractical to reverse would protect sellers from fraud, and routine escrow mechanisms could easily be implemented to protect buyers.  In this paper, we propose a solution to the double-spending problem using a peer-to-peer distributed timestamp server to generate computational proof of the chronological order of transactions.  The system is secure as long as honest nodes collectively control more CPU power than any cooperating group of attacker nodes.

# Transactions
   Each owner transfers the coin to the next by digitally signing a hash of the previous transaction and the public key of the next owner and adding these to the end of the coin.  A payee can verify the signatures to verify the chain of ownership.

we will use bezantin general problem to achieve consensus amount node in the network. the blockchain is built using hypercube approch
 to be sure that each node can easy make search and read on it.
# Verification
 We can not be sure that we don't have traitor in the network so we will 


# Network
The peer-to-peer network we want to build, will be virtually an hypercube. Du to fault that can appear in the network, we will use
k-consistent based hypercube. This means that a topology of the network is an hypercube but we add some link between node to be sure that fault should not divide the network in two or something like that.
## Node structure
    - physic_node
        - name
        - ip
        - protocol
        - neighbours (list of all neighbour)
        - private_key
        - public_key
every node join the network trough a particular core server which provide to each off them a copy of routing node of the network.
## Message
 - `Header`
 - `Data`
 - `Signature`
## Block structure
 - Block
    - `Header`: basic information about the chain and last state
    - `Data` : transactions and other data
    - `LastCommit` : +2/3 precommit signatures for the previous block

### Header 
 The block Header is composed of:
 - `ChainId (string) `: name of the blockchain, e.g. "sphyx"
 - `Height (int)` : sequential block number starting with 1
 - `Time (time)` : local time of the proposer who proposed this block
 - `LastBlockHash ([]byte)` : block hash of the previous block at height Height-1
 - `LastBlockParts (PartSetHeader)` : partset header of the previous block
 - `StateHash ([]byte)` : state hash of the state after processing this block   
### Data
 - `Txs ([]Tx)` : a list of transactions
### Commit

# next
bezantine general problem