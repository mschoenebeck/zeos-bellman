# ZEOS Bellman

ZEOS Bellman is a fully EOSIO compatible C++ implementation of the 'groth16' zk-SNARK verifier of the [bellman](https://github.com/zkcrypto/bellman/) crate used in ZCash Sapling. It contains the Implementation over curve BLS12-381 as implemented in the [bls12-381](https://github.com/zkcrypto/bls12_381) crate.

## Getting Started

Clone this repository:

```
git clone https://github.com/mschoenebeck/zeos-bellman.git
cd zeos-bellman
```

Head into the 'test' folder to run an example of a proof verification.

```bash
cd test
make run
```

The hard-coded strings inside `a.cpp` represent a verifying key `vk`, an actual `proof` as well as corresponding encoded public `inputs` of two different zero knowledge proofs.

To create your own zero knowledge proofs check out the [rustzeos](https://github.com/mschoenebeck/rustzeos) repository and create your own custom circuits as described [here](https://docs.rs/bellman/latest/bellman/). To create the strings of `vk`, `proof` and `inputs` use the `to_json()` function of `librustzeos`. See [test_librustzeos.rs](https://github.com/mschoenebeck/rustzeos/blob/main/testzeos/src/test_librustzeos.rs) for an example.

Note: In a production environment the `inputs` string need to be generated on chain (i.e. by the smart contract and not by the client) for security reasons. Use the `inputs_json()` function of the ZEOS smart contract [header file](https://github.com/mschoenebeck/thezeostoken/blob/e0fbc92168c549d3d22c6ee6b56d456de13b2809/contracts/eos/thezeostoken/zeos.hpp#L182) to pack the public inputs on chain.

## Dependencies

* [json_struct](https://github.com/mschoenebeck/json_struct) EOSIO compatible header-only library to parse json strings to C structs.

## Developer Dependencies

* [zeos.hpp](https://github.com/mschoenebeck/thezeostoken/blob/e0fbc92168c549d3d22c6ee6b56d456de13b2809/contracts/eos/thezeostoken/zeos.hpp) ZEOS header-only library for EOSIO smart contracts.

## Help
If you need help join us on [Telegram](https://t.me/ZeosOnEos).

## License

It's open source. Do with it whatever you want.

## Acknowledgments

Big thanks to the Electric Coin Company for developing, documenting and maintaining this awesome open source codebase for zk-SNARKs!

* [Zcash Protocol Specification](https://zips.z.cash/protocol/protocol.pdf)
